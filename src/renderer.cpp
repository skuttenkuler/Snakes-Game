//import renderer header file
#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer( const std::size_t screen_width,
                    const std::size_t screen_height,
                    const std::size_t grid_width,
                    const std::size_t grid_height
                ) : screen_width(screen_width),
                    screen_height(screen_height),
                    grid_width(grid_width),
                    grid_height(grid_height) {
            //Initialize SDL2
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                std::cerr << "Could not initialize SDL2.\n";
                std::cerr << "SDL@ Error: " << SDL_GetError() << "\n";
            }

            //create game window
           sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);
            
            if (nullptr == sdl_window) {
                std::cerr << "Could not create Game Window.\n";
                std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
            }

            // create game renderer
            sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
            if( nullptr == sdl_renderer) {
                    std::cerr << "Renderer Error.\n";
                    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
            }            
        }

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &apple) {
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    //clear the game screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E,0xFF);
    SDL_RenderClear(sdl_renderer);
    //render Apple
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    block.x = apple.x * block.w;
    block.y = apple.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);

    //render snake
    SDL_SetRenderDrawColor(sdl_renderer,  0x00, 0xFF, 0x00, 0xFF);
    for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    //render snake head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if(snake.alive) {
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);
  //update screen
  SDL_RenderPresent(sdl_renderer);

}

void Renderer::UpdateWindowTitle(int score, int fps) {
    std::string title{"Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
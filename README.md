# Snakes-Game
Snakes Game in C++

<img src="SnakeGame.gif"/>

## Code Snippet
*This snippet from game.cpp imports the controller and renderer class to update snake movement
```C++

void Game::Run(Controller const &controller, Renderer &renderer,
                std::size_t target_frame_duration) {
                    Uint32 title_timestamp = SDL_GetTicks();
                    Uint32 frame_start;
                    Uint32 frame_end;
                    Uint32 frame_duration;
                    int frame_count = 0;
                    bool running = true;

                    while(running) {
                        frame_start = SDL_GetTicks();

                        //input, update, and render main game loop
                        controller.HandleInput(running, snake);
                        Update();
                        renderer.Render(snake, apple);

                        frame_end = SDL_GetTicks();

                        //track the loop
                        frame_count++;
                        target_frame_duration = frame_end - frame_start;

                        //after every second update the window
                        if(frame_end - title_timestamp >= 1000) {
                            renderer.UpdateWindowTitle(score, frame_count);
                            frame_count = 0;
                            title_timestamp = frame_end;
                        }

                        //check if time for loop is too small, delay the loop so that we get correct frame rate
                        if(frame_duration < target_frame_duration) {
                            SDL_Delay(target_frame_duration - frame_duration);
                        }
                    }
                }
```
* This code snippet from renderer.cpp defines the snake and how it is rendered to the window
``` C++
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
```
## Dependencies
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * Installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. To compile: `cmake .. && make`
4. Start Game: `./SnakeGame`.
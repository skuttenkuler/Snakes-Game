#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceApple();
}

void Game::Run(Controller const &controller, Renderer &renderer,
                std::size_t target_frame_duration) {
                    Uint32 title_timestamp = SDL_GetTicks();
                    Uint32 frame_start;
                    Uint32 frame_end;
                    Uint32 frame_duration;
                    int frame_count = 0;
                    bool running = true

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
            void Game:: PlaceApple() {
                int x ,y;
                while(true) {
                    x = random_w(engine);
                    y = random_y(engine);
                    //make sure that the apple location is not occupied by the snake or prev apple already
                    if(!snake.SnakeCell(x,y)) {
                        apple.x = x;
                        food.y = y;
                        return;
                    }
                }
            }
            void Game::Update() {
                if(!snake.alive) return;
                snake.Update();

                int new_x = static_cast<int>(snake.head_x);
                int new_y = static_cast<int>(snake.head_y);

                //check for apple
                if(apple.x == new_x && apple.y == new_y) {
                    score ++
                    PlaceApple();
                    //grow snake and increase speed
                    snake.AddBody();
                    snake.speed += 0.02;
                }
            }
            int Game::GetScore() const {
                return score;
            }
            int Game::GetSize() const {
                return snake.size
            }
           
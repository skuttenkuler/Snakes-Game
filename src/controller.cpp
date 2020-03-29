//import controller header
#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                    Snake::Direction opposite) const {
                                        if(snake.direction != opposite || snake.size == 1) snake.direction = input;
                                        return;

                                    }
///Direction Controller Input Handler
void Controller::HandleInput(bool &running, Snake &snake) const {
    SDL_Event e;
    while (SDL_PollEvent (&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                //key symbol with direction input and the opposite direction of key pressed.
                ChangeDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
                break;
                case SDLK_DOWN:
                //key symbol with direction input and the opposite direction of key pressed.
                ChangeDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);
                break;
                case SDLK_LEFT:
                //key symbol with direction input and the opposite direction of key pressed.
                ChangeDirection(snake, Snake::Direction::kLeft, Snake::Direction::kRight);
                break;
                case SDLK_RIGHT:
                //key symbol with direction input and the opposite direction of key pressed.
                ChangeDirection(snake, Snake::Direction::kRight, Snake::Direction::kLeft);
                break;
            }
        }
    }
}
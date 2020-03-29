#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"


int main() {
    // set gmae screen and frames
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  //render game
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  //snake controller
  Controller controller;
  //game
  Game game(kGridWidth, kGridHeight);
  //run game
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
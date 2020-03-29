#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
    SDL_Point prev_cell{
        //get the head's cell before updating
        static_cast<int>(head_x),
        static_cast<int>(head_y)};
        
        UpdateHead();
    SDL_Point current_cell{
            //get the head's cell after updating
        static_cast<int>(head_x),
        static_cast<int>(head_y)};


    //when the snake head moves to new cell update the whole body
    if( current_cell.x != prev_cell.x || current_cell.y != prev_cell.y){
        AddBody(current_cell, prev_cell);
    }
    
}

void Snake::UpdateHead() {
    switch (direction) {
        case Direction::kUp:
            head_y -= speed;
            break;
        case Direction::kDown:
            heady_y -= speed;
            break;
        case Direction::kLeft:
            head_y -= speed;
            break;
        case Direction::kRight:
            head_y -= speed;
            break;

    }
    // wrap snake around to the starting point if off the screen
    head_x = fmod(head_x + grid_width, grid_width);
    head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::AddBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
    //make sure previous head location added to vector
    body.push_back(prev_head_cell);

    if(!growing) {
        //remove tail from vector
        body.erase(body.begin());
    } else {
        growing = false;
        size ++;
    }

    //check if snake died
    for (auto const &item : body) {
        if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
            alive = false;
        }
    }
}

void Snake::GrowBody() { growing = true; }

bool Snake::SnakeCell(int x, int y) {
    if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
        return true;
    }
    for (auto const &item : body) {
        if(x == item.x && y == item.y) {
            return true;
        }
    }
    return false;
}
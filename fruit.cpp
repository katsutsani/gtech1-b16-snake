#include "fruit.hpp"
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Fruit::Fruit(){
    randomSpawn();
};

Fruit::~Fruit(){}

void Fruit::randomSpawn(){
    srand(time(NULL));

    this->x = rand() % 19;
    this->y = rand() % 19;
}

void Fruit::DrawFruit(SDL_Renderer*renderer){
    SDL_Rect fruit;
    fruit.x =  this->x*25;
    fruit.y =  this->y*25;
    fruit.w = 25;
    fruit.h = 25;
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&fruit);
    SDL_RenderPresent(renderer);
}
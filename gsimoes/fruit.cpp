#include "fruit.hpp"

Fruit::Fruit(){
    randomSpawn();
};

Fruit::~Fruit(){}

void Fruit::randomSpawn(){
    this->x = rand() % 19;
    this-> y = rand() % 19;
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
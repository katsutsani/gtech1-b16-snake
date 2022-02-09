#include "fruit.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_image.h>

Fruit::Fruit(){
    this->x=0;
    this->y=0;
    randomSpawn();
};

Fruit::~Fruit(){

};

int last_x;
int last_y;

void Fruit::randomSpawn(){
    srand(time(NULL));
    last_x = this->x;
    last_y = this->y;
    this->x = rand() % 19;
    this->y = rand() % 19;
    if(last_x == this->x && last_y == this->y){
        randomSpawn();
    }
}

void Fruit::DrawFruit(SDL_Renderer*renderer){
    SDL_Surface * image = IMG_Load("sprites/elements/apple.png");
    SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    SDL_Rect src{this->x*25, this->y*25, 25, 25};
    SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderCopy(renderer, TextureImage, NULL,&src);
    SDL_DestroyTexture(TextureImage);
}
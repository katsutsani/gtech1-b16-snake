#include "fruit.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_image.h>

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
    SDL_Surface * image = IMG_Load("sprites/elements/apple.png");
    SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    SDL_Rect src{this->x*25, this->y*25, 25, 25};
    SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderCopy(renderer, TextureImage, NULL,&src);
    SDL_DestroyTexture(TextureImage);
}
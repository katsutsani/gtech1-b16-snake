#include "window.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

int longueur = 0;
int largeur = 0;

MainSDLWindow::MainSDLWindow(){
    this ->window=NULL;
    this ->renderer= NULL;
    this->font = NULL;
};
MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
};
int MainSDLWindow::Init(char* name,int lo,int la){
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return EXIT_FAILURE;
    };
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    this->font = TTF_OpenFont("font/comic-sans-ms.ttf",24);
    longueur = lo;
    largeur = la;
    window = SDL_CreateWindow(name,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,longueur,largeur,0);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    return EXIT_SUCCESS;
};
SDL_Renderer* MainSDLWindow::GetRenderer(void){
    return renderer;
};

SDL_Rect rect;

void MainSDLWindow::draw(){
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer,500, 500, 0, 500);
};

void MainSDLWindow::drawScore(int score){
    SDL_Color White = {255, 255, 255,0};
    std::string score_text = "Your Score : " + std::to_string(score);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font,score_text.c_str(), White); 
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect dest = { 10, 510, surfaceMessage->w, surfaceMessage->h };
    SDL_RenderCopy(renderer, Message, NULL, &dest);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
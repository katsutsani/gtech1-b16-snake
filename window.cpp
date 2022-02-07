#include "window.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int longueur = 0;
int largeur = 0;

MainSDLWindow::MainSDLWindow(){
    this ->window=NULL;
    this ->renderer= NULL;
};
MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};
int MainSDLWindow::Init(char* name,int lo,int la){
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return EXIT_FAILURE;
    };
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
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&rect);
    SDL_RenderPresent(renderer);
};
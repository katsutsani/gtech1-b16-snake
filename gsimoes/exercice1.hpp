#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class MainSDLWindow{
    public:
    
    MainSDLWindow(){
        this ->window=NULL;
        this ->renderer= NULL;
    };
    ~MainSDLWindow() {     // <- Destructeur, ici ne fait rien...
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    };

     int Init(char* name, int lo, int la){
         if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
            fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
            return EXIT_FAILURE;
        };
        window = SDL_CreateWindow(name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,lo,la,SDL_WINDOW_SHOWN);
        SDL_Delay(3000);
        return EXIT_SUCCESS;
    };

   SDL_Renderer* GetRenderer(void){
        return renderer;
    };

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

class MainSDLWindow{
    public:
    
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(char* name, int lo, int la);
    SDL_Renderer* GetRenderer(void);
    void draw();
    void drawScore(int score);

    private:
    TTF_Font* font;
    SDL_Window *window;
    SDL_Renderer *renderer;

};
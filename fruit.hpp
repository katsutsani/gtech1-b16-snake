#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Fruit{
    public:
    Fruit();
    ~Fruit();
    void randomSpawn();
    void DrawFruit(SDL_Renderer*renderer);
    int x;
    int y;
};
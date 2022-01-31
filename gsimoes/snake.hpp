#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.cpp"

class Snake {
    public:
    Snake();
    Snake(int x, int y);
    ~Snake();
    void Move(int direction);
    void Eat();
    void Print();
    Segment* Gethead(void);
    void drawHead(SDL_Renderer*,int x,int y);
    private:
    Segment* head;
};
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.cpp"

class Snake {
    public:
    Snake();
    ~Snake();
    int len();
    void Move(int direction);
    void Eat(int test);
    void Print();
    Segment* Gethead(void);
    Segment* Gettail(void);
    void drawHead(SDL_Renderer*,int x,int y);
    private:
    Segment* head;
    Segment* tail;
    int dir_prev;
    int prev_tail_x;
    int prev_tail_y;

};
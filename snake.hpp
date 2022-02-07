#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.cpp"

class Snake {
    public:
    Snake();
    ~Snake();
    int len();
    void Move(Segment*,int direction);
    void Eat();
    void Print();
    Segment* Gethead(void);
    Segment* Gettail(void);
    int GetDirPrev();
    void SetDirPrev(int direction);
    void draw(Segment*,SDL_Renderer*,int x,int y);
    int ColisionCheck();
    int prev_tail_x;
    int prev_tail_y;
    private:
    Segment* head;
    Segment* tail;
    int dir_prev;
};
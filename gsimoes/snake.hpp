#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.cpp"

class Snake {
    public:
    Snake();
    ~Snake();
    void Move(int direction);
    void Eat();
    void Print();
    private:
    Segment* head;
};
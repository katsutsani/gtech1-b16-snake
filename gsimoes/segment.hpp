#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Segment{
    public:
    Segment();
    ~Segment();
    int x;
    int y;
    private:
    Segment* next;
};
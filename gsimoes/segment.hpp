#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Segment{
    public:
    Segment();
    void Segment_();
    ~Segment();
    Segment* Getnext(void);
    void Setnext(Segment*);
    void drawSegment(SDL_Renderer*,int x,int y,int dir);
    void Print(int x,int y, int dir);
    int direction;
    int x;
    int y;
    private:
    Segment* next;
};
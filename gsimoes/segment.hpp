#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Segment{
    public:
    Segment();
    void Segment_();
    ~Segment();
    Segment* Getnext(void);
    void Setnext(int x,int y,int prevdir);
    void SegmentMove(int dir, int prev_tail_x,int prev_tail_y);
    void drawSegment(SDL_Renderer*);
    void Print(Segment*);
    int direction;
    int x;
    int y;
    private:
    Segment* next;
};
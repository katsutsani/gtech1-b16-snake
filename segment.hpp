#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Segment{
    public:
    Segment();
    void Segment_();
    ~Segment();
    Segment* Getnext(void);
    void Setnext(int x,int y,int prevdir,Segment*);
    void SegmentMove(int dir, int prev_tail_x,int prev_tail_y);
    void drawSegment(SDL_Renderer*, Segment*);
    int SegmentColisionCheck();
    void Print(Segment*);
    int direction;
    int x;
    int y;
    int next_prev_x;
    int next_prev_y;
    int next_prev_dir;
    private:
    Segment* next;
};
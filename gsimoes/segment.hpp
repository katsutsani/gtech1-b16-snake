#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Segment{
    public:
    Segment();
    ~Segment();
    Segment* Getnext(void);
    void Setnext(Segment*);
    void drawSegment();
    int direction;
    int x;
    int y;
    private:
    Segment* next;
};
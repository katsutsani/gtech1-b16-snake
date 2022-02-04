#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"
#include "fruit.hpp"
#include "segment.hpp"

class Playground :public Snake ,public fruit {
    public:
    Playground();
    ~Playground();
    Snake* GetSnake(void);
    fruit* GetFruit(void);
    int GetScore();
    void GenerateFruit();
    private:
    Snake* snake;
    int nbcol;
    int nbrow;
};
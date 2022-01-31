#include "snake.hpp"

Snake::Snake(){
    this->head = new Segment();
};

Snake::~Snake(){
    if(this->head != NULL){
        delete this->head;
    }
};

Segment* Snake::Gethead(){
    return head;
}

void Snake::Move(int direction){
    if (direction == 0){
        this->head->y -= 1;
        this->head->direction=0;
        if (this->head->y <= 0){
            this->head->y =0;

        }

    }
    else if (direction == 1){
        this->head->y += 1;
        this->head->direction=1;
        if (this->head->y >= 19){
            this->head->y =19;
        }            
    }
    else if (direction == 2){
        this->head->direction=2;
        this->head->x -= 1;
        if (this->head->x <= 0){
            this->head->x =0;
        }

    }
    else if (direction == 3){
        this->head->direction=3;
        this->head->x += 1;
        if (this->head->x >= 19){
            this->head->x =19;
        }
    }
};

void Snake::Print(){
    printf("(%d,%d)\n", this->head->x, this->head->y);
};

void Snake::Eat(){
    this->head->Setnext(head);
};

void Snake::drawHead(SDL_Renderer*name,int x,int y){
    SDL_Rect head;
    head.x =  x;
    head.y =  y;
    head.w = longueur/20;
    head.h = largeur/20;
    SDL_SetRenderDrawColor(name,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(name);
    SDL_SetRenderDrawColor(name,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(name,&head);
    SDL_RenderPresent(name);
}
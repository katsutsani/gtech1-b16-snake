#include "snake.hpp"

Snake::Snake(){
    this->head = new Segment();
    this->tail = new Segment();
};

Snake::~Snake(){
    if(this->head != NULL){
        delete this->head;
        delete this->tail;
    }
};

Segment* Snake::Gethead(){
    return head;
}

Segment* Snake::Gettail(){
    return tail;
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
    if (this->head->Getnext() != NULL){
        this->head->Getnext()->Print(this->head->x,this->head->y,this->head->direction);
    }
};

void Snake::Eat(int test){
    if(test == this->head->x){
        this->head->Setnext(head);
    }
};

void Snake::drawHead(SDL_Renderer*renderer,int x,int y){
    SDL_Rect head;
    head.x =  x;
    head.y =  y;
    head.w = longueur/20;
    head.h = largeur/20;
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&head);
    SDL_RenderPresent(renderer);
}
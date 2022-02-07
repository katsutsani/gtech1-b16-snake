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

int Snake::GetDirPrev(){
    return dir_prev;
}

void Snake::SetDirPrev(int direction){
    this->dir_prev = direction;
}

void Snake::Move(Segment*,int direction){
    this->prev_tail_x =this->head->x;
    this->prev_tail_y =this->head->y;
    this->dir_prev = this->head->direction;
    if(this->head->Getnext() != NULL){
        this->head->Getnext()->SegmentMove(this->dir_prev,this->prev_tail_x,this->prev_tail_y);
    }
    if (direction == 0){
        this->head->y -= 1;
        this->head->direction=0;
    }
    else if (direction == 1){
        this->head->y += 1;
        this->head->direction=1;       
    }
    else if (direction == 2){
        this->head->direction=2;
        this->head->x -= 1;
    }
    else if (direction == 3){
        this->head->direction=3;
        this->head->x += 1;
    }
};

void Snake::Print(){
    printf(" head (%d,%d)\n", this->head->x, this->head->y);
    if (this->head->Getnext() != NULL){
        this->head->Getnext()->Print(this->head->Getnext());
    }
};

void Snake::Eat(){
    if(this->head->Getnext() != NULL){
        this->head->Getnext()->Setnext(this->prev_tail_x,this->prev_tail_y,this->dir_prev,this->head->Getnext());
    }
    else{
        this->head->Setnext(this->prev_tail_x,this->prev_tail_y,this->dir_prev,this->head);
    }
};

void Snake::draw(Segment*,SDL_Renderer*renderer,int x,int y){
    SDL_Rect head;
    head.x =  x;
    head.y =  y;
    head.w = longueur/20;
    head.h = largeur/20;
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&head);
    if(this->head->Getnext() != NULL){
        this->head->Getnext()->drawSegment(renderer,this->head->Getnext());
    }
    else{
        SDL_RenderPresent(renderer);
    }
}

int Snake::ColisionCheck(){
    
}
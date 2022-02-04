#include "segment.hpp"

Segment::Segment(){
    this -> x = 0;
    this -> y = 0;
    this -> next = NULL;
    this->direction =-1;
}
Segment::~Segment(){
    if(this->next != NULL){
        delete this->next;
    }
}

Segment* Segment::Getnext(){
    return this->next;
}

void Segment::Setnext(Segment*, int x,int y, int prevdir){
    if (this->next != NULL){
        this->next->Setnext(this->next,x,y,prevdir);
    }
    else{
        this->next = new Segment();
        this->next->x = x;
        this->next->y = y;
        this->next->direction = prevdir;
    }
    
}

void Segment::Print(Segment*,int prev_dir){
    if(this->next != NULL){
        this->next->Print(this->next, prev_dir);
    }
    else{
        this->direction = prev_dir;
        if(this->direction == 0){
            printf("(%d,%d)",this->x,this->y); 
        }
        else if(this->direction == 1){
            printf("(%d,%d)",this->x,this->y); 
        }
        else if(this->direction == 2){
            printf("(%d,%d)",this->x,this->y); 
        }
        else if(this->direction == 3){
            printf("(%d,%d)",this->x,this->y); 
        }
    }

}

void Segment::drawSegment(Segment*,SDL_Renderer* renderer,int dir){
    SDL_Rect next;
    next.x =  x;
    next.y =  y;
    next.w = longueur/20;
    next.h = largeur/20;
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&next);
    if (this->Getnext() != NULL){
        this->Getnext()->drawSegment(this->Getnext(),renderer,dir);
    }
}
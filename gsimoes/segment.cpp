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

void Segment::Setnext(int x,int y, int prevdir){
    this->next = new Segment();
    this->next->x = x;
    this->next->y = y;
    this->next->direction = prevdir;
    
}

void Segment::SegmentMove(int dir, int prev_tail_x, int prev_tail_y){
    this->x = prev_tail_x;
    this->y = prev_tail_y;
    this->direction = dir;
    if(this->next != NULL){
        this->next->SegmentMove(this->direction,this->x,this->y);
    }
}

void Segment::Print(Segment*){
    if(this->next != NULL){
        this->next->Print(this->next);
    }
    else{
        printf("(%d,%d)",this->x,this->y); 
    }

}

void Segment::drawSegment(SDL_Renderer* renderer){
    SDL_Rect next;
    next.x =  this->x*25;
    next.y =  this->y*25;
    next.w = longueur/20;
    next.h = largeur/20;
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&next);
    if (this->Getnext() != NULL){
        this->Getnext()->drawSegment(renderer);
    }
    else{
        SDL_RenderPresent(renderer);
    }
}
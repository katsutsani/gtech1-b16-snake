#include "segment.hpp"

Segment::Segment(){
    this -> x = 0;
    this -> y = 0;
    this -> next = NULL;
    this->direction =-1;
    this->next_prev_x=0;
    this->next_prev_y =0;
    this->next_prev_dir = -1;
}
Segment::~Segment(){
    if(this->next != NULL){
        delete this->next;
    }
}

Segment* Segment::Getnext(){
    return this->next;
}

void Segment::Setnext(int x,int y, int prevdir, Segment*){
    if (this->next != NULL){
        prevdir=this->direction;
        this->next->Setnext(this->next_prev_x,this->next_prev_y,this->next_prev_dir,this->next);
    }
    else{
        this->next = new Segment();
        this->next->x = x;
        this->next->y = y;
        this->next->direction = prevdir;
    }
    
}

void Segment::SegmentMove(int dir, int prev_tail_x, int prev_tail_y){
    this->next_prev_x = this->x;
    this->next_prev_y = this->y;
    this->next_prev_dir = this->direction;
    if(this->next != NULL){
        this->next->SegmentMove(this->next_prev_dir,this->next_prev_x,this->next_prev_y);
    }
    this->x = prev_tail_x;
    this->y = prev_tail_y;
    this->direction = dir;
}

void Segment::Print(Segment*){
    if(this->next != NULL){
        printf(" next(%d,%d) ",this->x,this->y); 
        this->next->Print(this->next);
    }
    else{
        printf(" next(%d,%d) ",this->x,this->y); 
    }

}

void Segment::drawSegment(SDL_Renderer* renderer,Segment*){
    SDL_Rect next;
    next.x =  this->x*25;
    next.y =  this->y*25;
    next.w = 500/20;
    next.h = 500/20;
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&next);
    if (this->next != NULL){
        this->next->drawSegment(renderer,this->next);
    }
    else{
        SDL_RenderPresent(renderer);
    }
}

int Segment::checkCollision(Segment*head){
    if (head->x == this->next->x && head->y == this->next->y){
        return 1;
    }
    else{
        if(next->Getnext() != NULL){
            this->next->checkCollision(head);
        }
    }
}
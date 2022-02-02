#include "segment.hpp"

Segment::Segment(){
    this -> x = 0;
    this -> y = 0;
    this -> next = NULL;
    this->direction = -1;
}
Segment::~Segment(){
    if(this->next != NULL){
        delete this->next;
    }
}

Segment* Segment::Getnext(){
    return this->next;
}

void Segment::Setnext(Segment*){
    this->next = new Segment();
}

void Segment::Print(int x,int y, int dir){
    if(dir == 0){
        y+=1;
        printf("(%d,%d)",x,y); 
    }
    else if(dir == 1){
        y-=1;
        printf("(%d,%d)",x,y); 
    }
    else if(dir == 2){
        x+=1;
        printf("(%d,%d)",x,y); 
    }
    else if(dir == 3){
        x-=1;
        printf("(%d,%d)",x,y); 
    }
    printf("%d",this->next);
    if(this->next != NULL){
        this->next->Print(x,y,dir);
    }

}
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

void Segment::drawSegment(){
    if (this->next != NULL){
        drawSegment();
    }
}
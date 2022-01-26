#include "segment.hpp"

Segment::Segment(){
    this -> x = 0;
    this -> y = 0;
}
Segment::~Segment(){
    if(this->next != NULL){
        delete this->next;
    }
}
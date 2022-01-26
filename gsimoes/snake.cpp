#include "snake.hpp"

Snake::Snake(){
    this->head = new Segment();
};

Snake::~Snake(){
    if(this->head != NULL){
        delete this->head;
    }
};

void Snake::Move(int direction){
    if (direction == 0){
        this->head->y -= 1;
        if (this->head->y <= 0){
            this->head->y =0;
            direction = -1;

        }
        printf("test");

    }
    else if (direction == 1){
        this->head->y += 1;
        if (this->head->y >= 20){
            this->head->y =20;
            direction = -1;
        }
        printf("test2");            
    }
    else if (direction == 2){
        this->head->x -= 1;
        if (this->head->x <= 0){
            this->head->x =0;
            direction = -1;
        }
        printf("test3");

    }
    else if (direction == 3){
        this->head->x += 1;
        if (this->head->x >= 20){
            this->head->x =20;
            direction = -1;
        }
        printf("test4");
    }
};

void Snake::Print(){
    printf("(%d,%d)\n", this->head->x, this->head->y);
};
#include "snake.hpp"
#include <SDL2/SDL_image.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define NONE -1

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
        this->head->Getnext()->SegmentMove(this->dir_prev,this->prev_tail_x,this->prev_tail_y, this->head);
    }
    if (direction == UP){
        this->head->y -= 1;
        this->head->direction=UP;
    }
    else if (direction == DOWN){
        this->head->y += 1;
        this->head->direction=DOWN;       
    }
    else if (direction == LEFT){
        this->head->direction=LEFT;
        this->head->x -= 1;
    }
    else if (direction == RIGHT){
        this->head->direction=RIGHT;
        this->head->x += 1;
    }
};

void Snake::Print(){
    printf(" head (%d,%d)", this->head->x, this->head->y);
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
    if(this->head->direction == UP){
        SDL_Surface * image = IMG_Load("sprites/head/head_top.png");
        SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_Rect src{x,y, 500/20, 500/20};
        SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderCopy(renderer, TextureImage, NULL,&src);
        SDL_DestroyTexture(TextureImage);
    }
    else if(this->head->direction == DOWN){
        SDL_Surface * image = IMG_Load("sprites/head/head_bot.png");
        SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_Rect src{x,y, 500/20, 500/20};
        SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderCopy(renderer, TextureImage, NULL,&src);
        SDL_DestroyTexture(TextureImage);
    }
    else if(this->head->direction == LEFT){
        SDL_Surface * image = IMG_Load("sprites/head/head_left.png");
        SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_Rect src{x,y, 500/20, 500/20};
        SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderCopy(renderer, TextureImage, NULL,&src);
        SDL_DestroyTexture(TextureImage);
    }
    else if(this->head->direction == RIGHT){
        SDL_Surface * image = IMG_Load("sprites/head/head_right.png");
        SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_Rect src{x,y, 500/20, 500/20};
        SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderCopy(renderer, TextureImage, NULL,&src);
        SDL_DestroyTexture(TextureImage);
    }
    else{
        SDL_Surface * image = IMG_Load("sprites/head/head_top.png");
        SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
        SDL_Rect src{x,y, 500/20, 500/20};
        SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
        SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderCopy(renderer, TextureImage, NULL,&src);
        SDL_DestroyTexture(TextureImage);
    }
    if(this->head->Getnext() != NULL){
        this->head->Getnext()->drawSegment(renderer,this->head->Getnext(),"None");
    }
}

int Snake::ColisionCheck(){
    
}
#include "segment.hpp"
#include <SDL2/SDL_image.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define NONE -1

Segment::Segment(){
    this -> x = 0;
    this -> y = 0;
    this -> next = NULL;
    this->direction = NONE;
    this->next_prev_x=0;
    this->next_prev_y =0;
    this->next_prev_dir = NONE;
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

void Segment::SegmentMove(int dir, int prev_tail_x, int prev_tail_y,Segment* ref){
    if(ref->direction == UP && this->x == prev_tail_x || ref->direction == DOWN && this->x == prev_tail_x ){
        this->next_prev_x = this->x;
        this->next_prev_y = this->y;
        this->next_prev_dir = ref->direction;
        this->x = prev_tail_x;
        this->y = prev_tail_y;
        this->direction = ref->direction;
    }
    else if(ref->direction == LEFT && this->y == prev_tail_y || ref->direction == RIGHT && this->y == prev_tail_y ){
        this->next_prev_x = this->x;
        this->next_prev_y = this->y;
        this->next_prev_dir = ref->direction;
        this->x = prev_tail_x;
        this->y = prev_tail_y;
        this->direction = ref->direction;
    }
    else{
        this->next_prev_x = this->x;
        this->next_prev_y = this->y;
        this->next_prev_dir = this->direction;
        this->x = prev_tail_x;
        this->y = prev_tail_y;
        this->direction = dir;
    }
    if(this->next != NULL){
        this->next->SegmentMove(this->next_prev_dir,this->next_prev_x,this->next_prev_y,this);
    }
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

void Segment::drawSegment(SDL_Renderer* renderer,Segment*,char* angle){
    if (this->next != NULL){
        if(this->next_prev_dir != this->direction && angle == "None"){
            if(this->direction == RIGHT && this ->next_prev_dir == DOWN || this->direction == UP && this ->next_prev_dir == LEFT){
                angle = "DRoLU";
            }
            else if(this->direction == RIGHT && this ->next_prev_dir == UP || this->direction == DOWN && this ->next_prev_dir == LEFT){
                angle = "URoLD";
            }
            else if(this->direction == DOWN && this ->next_prev_dir == RIGHT || this ->direction == LEFT && this->next_prev_dir == UP){
                angle = "RDoUL";
            }
            else if(this->direction == LEFT && this->next_prev_dir == DOWN || this->direction == UP && this->next_prev_dir == RIGHT){
                angle = "DLoRU";
            }
        }
        else{
            angle = "None";
        }
        if(angle == "None"){
            if(this->direction == UP || this->direction == DOWN){
                angle = "None";
                SDL_Surface * image = IMG_Load("sprites/body/body_axis_y.png");
                SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
                SDL_FreeSurface(image);
                SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
                SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(renderer, TextureImage, NULL,&src);
                SDL_DestroyTexture(TextureImage);
            }
            else if(this->direction == LEFT || this->direction == RIGHT){
                angle = "None";
                SDL_Surface * image = IMG_Load("sprites/body/body_axis_x.png");
                SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
                SDL_FreeSurface(image);
                SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
                SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(renderer, TextureImage, NULL,&src);
                SDL_DestroyTexture(TextureImage);
            }
        }
        else{
            if(angle =="DRoLU"){
                SDL_Surface * image = IMG_Load("sprites/body/body_turning_bot_right.png");
                SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
                SDL_FreeSurface(image);
                SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
                SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(renderer, TextureImage, NULL,&src);
                SDL_DestroyTexture(TextureImage);
            }
            else if(angle =="URoLD"){
                SDL_Surface * image = IMG_Load("sprites/body/body_turning_top_right.png");
                SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
                SDL_FreeSurface(image);
                SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
                SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(renderer, TextureImage, NULL,&src);
                SDL_DestroyTexture(TextureImage);
            }
            else if(angle =="RDoUL"){
                SDL_Surface * image = IMG_Load("sprites/body/body_turning_top_left.png");
                SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
                SDL_FreeSurface(image);
                SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
                SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(renderer, TextureImage, NULL,&src);
                SDL_DestroyTexture(TextureImage);
            }
            else if(angle =="DLoRU"){
                SDL_Surface * image = IMG_Load("sprites/body/body_turning_bot_left.png");
                SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
                SDL_FreeSurface(image);
                SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
                SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
                SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(renderer, TextureImage, NULL,&src);
                SDL_DestroyTexture(TextureImage);
            }
        }
        this->next->drawSegment(renderer,this->next,angle);
    }
    else{
        if(this->direction == UP){

            SDL_Surface * image = IMG_Load("sprites/tail/tail_bot.png");
            SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
            SDL_FreeSurface(image);
            SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
            SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
            SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
            SDL_RenderCopy(renderer, TextureImage, NULL,&src);
            SDL_DestroyTexture(TextureImage);
        }
        else if(this->direction == DOWN){
            SDL_Surface * image = IMG_Load("sprites/tail/tail_top.png");
            SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
            SDL_FreeSurface(image);
            SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
            SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
            SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
            SDL_RenderCopy(renderer, TextureImage, NULL,&src);
            SDL_DestroyTexture(TextureImage);
        }
        else if(this->direction == LEFT){
            SDL_Surface * image = IMG_Load("sprites/tail/tail_right.png");
            SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
            SDL_FreeSurface(image);
            SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
            SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
            SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
            SDL_RenderCopy(renderer, TextureImage, NULL,&src);
            SDL_DestroyTexture(TextureImage);
        }
        else if(this->direction == RIGHT){
            SDL_Surface * image = IMG_Load("sprites/tail/tail_left.png");
            SDL_Texture* TextureImage = SDL_CreateTextureFromSurface(renderer, image);
            SDL_FreeSurface(image);
            SDL_Rect src{this->x*25,this->y*25, 500/20, 500/20};
            SDL_QueryTexture(TextureImage, nullptr, nullptr, &src.w, &src.h);
            SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
            SDL_RenderCopy(renderer, TextureImage, NULL,&src);
            SDL_DestroyTexture(TextureImage);
        }
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
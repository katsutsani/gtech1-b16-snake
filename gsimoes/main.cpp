#include "window.cpp"
#include "snake.cpp"

int direction = -1;

int logrid = longueur/20;
int lagrid = largeur/20;

void update(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	if ( keystates[SDL_SCANCODE_UP] ) {
        if (direction != 1){
            direction = 0;
        }
	}
	if ( keystates[SDL_SCANCODE_DOWN] ) {
        if (direction != 0){
            direction =1;
        }
	}
	if ( keystates[SDL_SCANCODE_LEFT] ) {
        if(direction != 3){
            direction = 2;
        }
	}
	if ( keystates[SDL_SCANCODE_RIGHT] ) {
        if (direction !=2){
            direction = 3;
        }
	}
}



int main(void) {
    rect.x = 1*logrid;
    rect.y = 1*lagrid;
    rect.w = 32;
    rect.h = 32;
    Snake *snake = NULL;
    snake = new Snake();
    MainSDLWindow main_window; 
    SDL_Event events;
    main_window.Init("test",500,500);
    bool isOpen = true; 
    Uint32 frameStart, frameTime, frameDelay = 20;
    while (isOpen){
        frameStart = SDL_GetTicks();
        while (SDL_PollEvent(&events))
        {
            if ( events.type == SDL_QUIT ) {
				isOpen = false;
			}
			else if ( events.type == SDL_KEYDOWN ) {
				switch ( events.key.keysym.sym ) {
				case SDLK_ESCAPE:
					isOpen = false;
					break;
				}
			}
            
        }
        update();
        snake ->Move(direction);
        snake->Print();
        if (direction == 0){
            rect.y -= 1*50;
            if (rect.y <= 0){
                rect.y =0;
                direction = -1;
            }

        }
        else if (direction == 1){
            rect.y += 1*50;
            if (rect.y >= 500-32){
                rect.y =500-32;
                direction = -1;
            }
                
        }
        else if (direction == 2){
            rect.x -= 1*50;
            if (rect.x <= 0){
                rect.x =0;
                direction = -1;
            }

        }
        else if (direction == 3){
            rect.x += 1*50;
            if (rect.x >= 500-32){
                rect.x =500-32;
                direction = -1;
            }

        }
        main_window.draw();
        frameTime = SDL_GetTicks() - frameStart;
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
		}
    }
    if(snake != NULL){
        delete snake;
    }

    
};
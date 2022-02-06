#include "window.cpp"
#include "snake.cpp"
#include "fruit.cpp"


int direction = -1;

int logrid;
int lagrid;

void update(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	if ( keystates[SDL_SCANCODE_UP] ) {
        if (direction != 1){
            direction = 0;
        }
        return;
	}
	if ( keystates[SDL_SCANCODE_DOWN] ) {
        if (direction != 0){
            direction =1;
        }
        return;
	}
	if ( keystates[SDL_SCANCODE_LEFT] ) {
        if(direction != 3){
            direction = 2;
        }
        return;
	}
	if ( keystates[SDL_SCANCODE_RIGHT] ) {
        if (direction !=2){
            direction = 3;
        }
        return;
	}
}



int main(void) {    
    MainSDLWindow main_window; 
    SDL_Event events;
    main_window.Init("test",500,500);
    int x = longueur/2;
    int y = largeur/2;
    logrid = longueur/20;
    lagrid = largeur/20;
    Snake *snake = NULL;
    snake = new Snake();
    Fruit *fruit = NULL;
    fruit = new Fruit();
    bool isOpen = true; 
    Uint32 iter;
    snake->Gethead()->x = 9;
    snake->Gethead()->y = 9;
    int snake_speed_fpc = 7;
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
        snake->SetDirPrev(direction);
        update();

        if (iter % snake_speed_fpc == 0) {
            snake ->Move(snake->Gethead(),direction);
        }
        x =snake->Gethead()->x*logrid;
        y =snake->Gethead()->y*lagrid;

        if(snake->Gethead()->x == fruit->x && snake->Gethead()->y == fruit->y){
            snake->Eat();
            fruit->randomSpawn();
        }
        snake->Print();
        fruit->DrawFruit(main_window.GetRenderer());
        snake->draw(snake->Gethead(),main_window.GetRenderer(),x,y);
        frameTime = SDL_GetTicks() - frameStart;
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
		}
        iter++;
    }
    if(snake != NULL){
        delete snake;
    }

    
};
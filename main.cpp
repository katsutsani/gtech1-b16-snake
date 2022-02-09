#include "window.cpp"
#include "snake.cpp"
#include "fruit.cpp"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define NONE -1
int direction= NONE;
int lose;
int logrid;
int lagrid;
int alreadyChanged;


int main(void) {    
    MainSDLWindow main_window; 
    SDL_Event events;
    SDL_Event eventsMove;
    int score = 0;
    main_window.Init("test",500,550);
    int x = 500/2;
    int y = 500/2;
    logrid = 500/20;
    lagrid = 500/20;
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
        SDL_SetRenderDrawColor(main_window.GetRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(main_window.GetRenderer());
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
                    case SDLK_UP:
                        if(direction != DOWN && alreadyChanged != 1){
                            alreadyChanged = 1;
                            direction = UP;
                            break;
                        }
                            
                    case SDLK_DOWN:
                        if (direction != UP && alreadyChanged != 1 || direction != NONE && alreadyChanged != 1){
                            alreadyChanged = 1;
                            direction = 1;
                            break;
                        }
                            
                    case SDLK_LEFT:
                        if (direction != RIGHT && alreadyChanged != 1){
                            alreadyChanged = 1;
                            direction = LEFT;
                            break;
                        }
                    case SDLK_RIGHT:
                        if (direction != LEFT && alreadyChanged != 1){
                            alreadyChanged = 1;
                            direction = RIGHT;
                            break;
                        }
				}
			}         
        }
        snake->SetDirPrev(direction);

        if (iter % snake_speed_fpc == 0) {
            alreadyChanged = 0;
            snake->Move(snake->Gethead(),direction);
            if(snake->Gethead()->x < 0 || snake->Gethead()->y < 0||snake->Gethead()->x > 19 || snake->Gethead()->y > 19){
                isOpen = false;
                break;
            }
            if(snake->Gethead()->x == fruit->x && snake->Gethead()->y == fruit->y){
                snake->Eat();
                fruit->randomSpawn();
                score ++;
            }
            if(snake->Gethead()->Getnext() != NULL){
                lose = snake->Gethead()->checkCollision(snake->Gethead());
                if (lose == 1){
                    break;
                }
            }
        }
        x =snake->Gethead()->x*logrid;
        y =snake->Gethead()->y*lagrid;
        snake->draw(snake->Gethead(),main_window.GetRenderer(),x,y);
        main_window.draw();
        fruit->DrawFruit(main_window.GetRenderer());
        main_window.drawScore(score);
        SDL_RenderPresent(main_window.GetRenderer());
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
    if(fruit != NULL){
        delete fruit;
    }
};
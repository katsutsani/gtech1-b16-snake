#include "exercices.hpp"

MainSDLWindow::MainSDLWindow(){
    this ->window=NULL;
    this ->renderer= NULL;
};
MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};
int MainSDLWindow::Init(char* name, int lo, int la){
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return EXIT_FAILURE;
    };
    window = SDL_CreateWindow(name,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,lo,la,SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    return EXIT_SUCCESS;
};
SDL_Renderer* MainSDLWindow::GetRenderer(void){
    return renderer;
};

SDL_Rect rect;


void MainSDLWindow::draw(){
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&rect);
    SDL_RenderPresent(renderer);
};

void update(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	if ( keystates[SDL_SCANCODE_UP] ) {
		rect.y -= 10;
        if (rect.y <= 0)
            rect.y =0;
	}
	if ( keystates[SDL_SCANCODE_DOWN] ) {
		rect.y += 10;
        if (rect.y >= 500-32)
            rect.y =500-32;
	}
	if ( keystates[SDL_SCANCODE_LEFT] ) {
		rect.x -= 10;
        if (rect.x <= 0)
            rect.x =0;
	}
	if ( keystates[SDL_SCANCODE_RIGHT] ) {
		rect.x += 10;
        if (rect.x >= 500-32)
            rect.x =500-32;
	}
    if ( keystates[SDL_SCANCODE_UP] && keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_UP] && keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_DOWN] && keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_DOWN] && keystates[SDL_SCANCODE_RIGHT]) {
	}
}



int main(void) {
    rect.x = 50;
    rect.y = 50;
    rect.w = 32;
    rect.h = 32;
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
        main_window.draw();
        frameTime = SDL_GetTicks() - frameStart;
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
		}
    }
    main_window.~MainSDLWindow();  
    
};

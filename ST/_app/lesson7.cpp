#include "_app/lesson7.h"

#include "SDL/SDL_ttf.h"

st::_app::lesson7::lesson7() { }

st::_app::lesson7::~lesson7() { }

void st::_app::lesson7::run() {
    SDL_Surface *background = NULL;
    SDL_Surface *message = NULL;
    
    TTF_Font *font = NULL;
    SDL_Color textColor = { 255, 255, 255 };

    initialize_screen();

    flip();
    delay();
}

bool st::_app::lesson7::init() {
    return ( st::_app::sdl::init() && 
            TTF_Init() == -1 );
}

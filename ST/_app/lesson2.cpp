#include "_app/lesson2.h"
#include "SDL/SDL.h"

st::_app::lesson2::lesson2() { }

st::_app::lesson2::~lesson2() { }

void st::_app::lesson2::run() {
    SDL_Surface* message = NULL;
    SDL_Surface* background = NULL;
    initialize_screen();
    if ( message != NULL ) { SDL_FreeSurface(message); }
    if ( background != NULL ) { SDL_FreeSurface(background); }
}

#include "_app/sdl.h"
#include "SDL/SDL.h"

st::_app::sdl::sdl() {
    init();
}

st::_app::sdl::~sdl() {
    finish();
}

bool st::_app::sdl::init() {
    SDL_Init ( SDL_INIT_EVERYTHING );
    // Let's be honest, right now I don't care. # COPIED!!!
    return true;
}

bool st::_app::sdl::finish() {
    SDL_Quit();
    // Let's be honest, right now I don't care.
    return true;
}

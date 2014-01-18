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
    SDL_Surface* hello;
    m_screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE );
    // Let's be honest, right now I don't care. # COPIED!!!
    hello = SDL_LoadBMP(media()->get_image_media_path("hello.bmp").c_str());
    SDL_BlitSurface(hello, NULL, m_screen, NULL);
    // Lazy!
    SDL_Flip( m_screen );
    SDL_Delay( 2000 );
    SDL_FreeSurface(hello);
    return true;
}

bool st::_app::sdl::finish() {
    SDL_Quit();
    // Let's be honest, right now I don't care.
    return true;
}

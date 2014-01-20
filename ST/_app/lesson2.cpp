#include "_app/lesson2.h"
#include "SDL/SDL.h"

st::_app::lesson2::lesson2() { }

st::_app::lesson2::~lesson2() { }

void st::_app::lesson2::run() {
    SDL_Surface* message = NULL;
    SDL_Surface* background = NULL;
    initialize_screen("lesson2");
    background = load_image( "background.bmp" );
    message = load_image( "hello-small.bmp" );
    apply_surface(0,   0,   background);
    apply_surface(320, 0,   background);
    apply_surface(0,   240, background);
    apply_surface(320, 240, background);
    apply_surface(160, 120,  message);
    flip();
    delay( 2000 );
    free_surface( message );
    free_surface( background );
}

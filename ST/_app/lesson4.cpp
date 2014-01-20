#include "_app/lesson4.h"

st::_app::lesson4::lesson4() { }
st::_app::lesson4::~lesson4() { }

void st::_app::lesson4::run() {
    SDL_Surface* image = NULL;
    // Could, should this be a member?  Should I just have a
    // standard loop that I can start up.  I'll refactor this
    // soonish.
    SDL_Event event;
    bool quit = false;
    initialize_screen( "Event Test" );
    image = load_image( "x.png" );
    apply_surface(0, 0, image);
    flip();
    // Will need to rework event loop somehow...
    while ( quit == false ) {
        while ( SDL_PollEvent(&event) ) {
            if ( event.type == SDL_QUIT ) {
                quit = true;
            }
        }
    }
    free_surface( image );
    finish();
}

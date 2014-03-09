#include "_app/sdl_poll.h"

st::_app::sdl_poll::sdl_poll() { }
st::_app::sdl_poll::~sdl_poll() { }

void st::_app::sdl_poll::run() {
    SDL_Surface* image = NULL;
    // Could, should this be a member?  Should I just have a
    // standard loop that I can start up.  I'll refactor this
    // soonish.
    bool quit = false;
    initialize_screen( "Event Test" );
    image = load_image( "x.png" );
    apply_surface(0, 0, image);
    flip();
    // Will need to rework event loop somehow...
    start();
    free_surface( image );
}

void st::_app::sdl_poll::start() {
    SDL_Event event;
    while ( m_quit == false ) {
        while ( SDL_PollEvent(&event) ) {
            if ( event.type == SDL_QUIT ) {
                m_quit = true;
            } else {
                event_handler(&event);
            }
        }
    }
}

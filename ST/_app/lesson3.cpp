#include "_app/lesson3.h"

st::_app::lesson3::lesson3() { }
st::_app::lesson3::~lesson3() { }

void st::_app::lesson3::run() {
    SDL_Surface* hello;
    initialize_screen();
    hello = load_image("look.png");
    apply_surface(0, 0, hello);
    flip();
    delay();
    free_surface( hello );
}

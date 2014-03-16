#include "_app/lesson10.h"

st::_app::lesson10::lesson10() { }

st::_app::lesson10::~lesson10() { }

void st::_app::lesson10::run() {
    initialize_screen();
    flip();
    start();
}

void st::_app::lesson10::event_handler(SDL_Event* event) {
    flip();
}

#include "app.h"
#include <cstddef>

// TODO: Make this more flexible base on CMake initial
// assumptions.  Too lazy.
#include "_app/sdl.h"

st::app::app() { }

st::app::~app() { }

st::app* st::app::build_app ( st::st_app_type app_type ) {
    if ( app_type == st::SDL ) {
        return new st::_app::sdl();
    }
    return NULL;
}

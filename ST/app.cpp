#include "app.h"
#include <cstddef>

// TODO: Make this more flexible base on CMake initial
// assumptions.  Too lazy.
#include "_app/sdl.h"
#include "_app/lesson2.h"

st::app::app() { 
    m_st_media = new st::media();
}

st::app::~app() {
    delete m_st_media;
}

st::app* st::app::build_app ( std::string name ) {
    /* TODO: Yeah, yeah, case to come. */
    if ( name == "sdl" ) {
        return new st::_app::sdl();
    } else if ( name == "lesson2" ) {
        return new st::_app::lesson2();
    }
    return NULL;
}

st::media* st::app::media() {
    return m_st_media;
}

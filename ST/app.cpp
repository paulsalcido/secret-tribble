#include "app.h"
#include <cstddef>

// TODO: Make this more flexible base on CMake initial
// assumptions.  Too lazy.
#include "_app/sdl.h"
#include "_app/lesson2.h"
#include "_app/lesson3.h"
#include "_app/lesson4.h"
#include "_app/lesson5.h"
#include "_app/lesson6.h"

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
    } else if ( name == "lesson3" ) {
        return new st::_app::lesson3();
    } else if ( name == "lesson4" ) {
        return new st::_app::lesson4();
    } else if ( name == "lesson5" ) {
        return new st::_app::lesson5();
    } else if ( name == "lesson6" ) {
        return new st::_app::lesson6();
    }
    return NULL;
}

st::media* st::app::media() {
    return m_st_media;
}

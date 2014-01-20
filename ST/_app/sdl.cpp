#include "_app/sdl.h"

#include <string>
#include <iostream>
#include "SDL/SDL_image.h"

st::_app::sdl::sdl() {
    init();
}

st::_app::sdl::~sdl() {
    finish();
}

bool st::_app::sdl::init() {
    return ( SDL_Init ( SDL_INIT_EVERYTHING ) != -1 );
}

bool st::_app::sdl::finish() {
    SDL_Quit();
    return true;
}

bool st::_app::sdl::initialize_screen(std::string caption, int width, int height, int bpp) {
    m_screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE );
    if ( m_screen == NULL ) {
        return false;
    }
    SDL_WM_SetCaption(caption.c_str(), NULL);
    return true;
}

bool st::_app::sdl::flip() {
    return ( SDL_Flip( m_screen ) != -1 );
}

void st::_app::sdl::free_surface(SDL_Surface* surface) {
    if ( surface != NULL ) { SDL_FreeSurface(surface); }
}

void st::_app::sdl::run() {
    SDL_Surface* hello;
    initialize_screen();
    hello = load_image("hello.bmp", false);
    apply_surface(0, 0, hello);
    flip();
    delay( 2000 );
    free_surface(hello);
}

SDL_Surface* st::_app::sdl::_load_image(std::string name, bool optimize, bool sdl_image, st::_app::sdl_color_map* color_map) {
    SDL_Surface* optimized_image = NULL;
    SDL_Surface* loaded_image = sdl_image ?
        IMG_Load( media()->get_image_media_path(name).c_str() ) :
        SDL_LoadBMP(media()->get_image_media_path(name).c_str());
    if ( loaded_image != NULL && optimize ) {
        optimized_image = SDL_DisplayFormat( loaded_image );
        SDL_FreeSurface( loaded_image );
    } else if ( loaded_image != NULL ) {
        optimized_image = loaded_image;
    } else {
        std::cerr << "Warning: could not load image " << name << std::endl;
    }
    if ( optimized_image != NULL and color_map != NULL ) {
        color_map->set_color_key(optimized_image);
    }
    return optimized_image;
}

SDL_Surface* st::_app::sdl::load_bitmap(std::string name, bool optimize, st::_app::sdl_color_map* color_map) {
    return _load_image(name, optimize, false, color_map);
}

SDL_Surface* st::_app::sdl::load_image(std::string name, bool optimize, st::_app::sdl_color_map* color_map) {
    return _load_image(name, optimize, true, color_map);
}

void st::_app::sdl::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    if ( destination == NULL ) {
        destination = m_screen;
    }
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void st::_app::sdl::delay( int del ) {
    SDL_Delay( del );
}

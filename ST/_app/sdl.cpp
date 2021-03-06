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
    return ( SDL_Init ( SDL_INIT_EVERYTHING ) != -1 && TTF_Init() != -1 );
}

bool st::_app::sdl::finish() {
    TTF_Quit();
    SDL_Quit();
    return true;
}

bool st::_app::sdl::initialize_screen(std::string caption, int width, int height, int bpp) {
    m_current_width = width;
    m_current_height = height;
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

void st::_app::sdl::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* rect) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    if ( destination == NULL ) {
        destination = m_screen;
    }
    SDL_BlitSurface(source, rect, destination, &offset);
}

void st::_app::sdl::apply_surface_clip(int x, int y, SDL_Surface* source, SDL_Rect* rect) {
    apply_surface(x, y, source, m_screen, rect);
}

void st::_app::sdl::delay( int del ) {
    SDL_Delay( del );
}

TTF_Font* st::_app::sdl::load_font(std::string name, int height) {
    TTF_Font* tmp = TTF_OpenFont( media()->get_typeface_media_path(name).c_str(), height );
    std::cerr << TTF_GetError() << std::endl;
    return tmp;
}

bool st::_app::sdl::init_audio() {
    return Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) != -1;
}

Mix_Music* st::_app::sdl::load_music(std::string name) {
    return Mix_LoadMUS( media()->get_sound_media_path(name).c_str() );
}

Mix_Chunk* st::_app::sdl::load_sound_chunk(std::string name) {
    return Mix_LoadWAV( media()->get_sound_media_path(name).c_str() );
}

void st::_app::sdl::free_media( TTF_Font *&font ) {
    if ( font != NULL ) TTF_CloseFont( font );
    font = NULL;
}

void st::_app::sdl::free_media( Mix_Chunk *&chunk ) {
    if ( chunk != NULL ) Mix_FreeChunk( chunk );
    chunk = NULL;
}

void st::_app::sdl::free_media( Mix_Music *&music ) {
    if ( music != NULL ) Mix_FreeMusic( music );
    music = NULL;
}

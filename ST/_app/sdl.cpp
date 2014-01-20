#include "_app/sdl.h"

st::_app::sdl::sdl() {
    init();
}

st::_app::sdl::~sdl() {
    finish();
}

bool st::_app::sdl::init() {
    SDL_Init ( SDL_INIT_EVERYTHING );
    return true;
}

bool st::_app::sdl::finish() {
    SDL_Quit();
    return true;
}

void st::_app::sdl::initialize_screen() {
    m_screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE );
}

void st::_app::sdl::flip() {
    SDL_Flip( m_screen );
}

void st::_app::sdl::run() {
    SDL_Surface* hello;
    initialize_screen();
    // Let's be honest, right now I don't care. # COPIED!!!
    hello = load_image("hello.bmp", false);
    // SDL_BlitSurface(hello, NULL, m_screen, NULL);
    // Lazy!
    apply_surface(0, 0, hello);
    flip();
    SDL_Delay( 2000 );
    SDL_FreeSurface(hello);
}

SDL_Surface* st::_app::sdl::load_image(std::string name, bool optimize) {
    SDL_Surface* optimized_image = NULL;
    SDL_Surface* loaded_image = SDL_LoadBMP(media()->get_image_media_path(name).c_str());
    if ( loaded_image != NULL && optimize ) {
        optimized_image = SDL_DisplayFormat( loaded_image );
        SDL_FreeSurface( loaded_image );
    } else if ( loaded_image != NULL ) {
        optimized_image = loaded_image;
    }
    return optimized_image;
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

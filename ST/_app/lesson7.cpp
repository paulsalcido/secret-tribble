#include "_app/lesson7.h"
#include <iostream>

st::_app::lesson7::lesson7() {
    init();
}

st::_app::lesson7::~lesson7() { }

void st::_app::lesson7::run() {
    SDL_Surface *background = NULL;
    SDL_Surface *message = NULL;
    
    TTF_Font *font = NULL;
    SDL_Color textColor = { 255, 255, 255 };

    initialize_screen();

    font = load_font("lazy.ttf",28);
    message = TTF_RenderText_Solid(font, "The quick brown fox jumps over the lazy dog.", textColor);
    background = load_image("background.png");

    apply_surface(0, 0, background);
    apply_surface(0, 150, message);

    flip();
    delay();
}

bool st::_app::lesson7::init() {
    return ( TTF_Init() == -1 );
}

TTF_Font* st::_app::lesson7::load_font(std::string name, int height) {
    TTF_Font* tmp = TTF_OpenFont( media()->get_typeface_media_path(name).c_str(), height );
    std::cerr << TTF_GetError() << std::endl;
    return tmp;
}

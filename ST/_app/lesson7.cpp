#include "_app/lesson7.h"
#include <iostream>

st::_app::lesson7::lesson7() { }

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

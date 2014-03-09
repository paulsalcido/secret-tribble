#include "_app/lesson8.h"

st::_app::lesson8::lesson8() {
    m_font = NULL;
    m_upmessage =
        m_downmessage =
        m_leftmessage =
        m_rightmessage=
        NULL;
    // m_textcolor = { 255, 255, 255 };
}

st::_app::lesson8::~lesson8() { }

void st::_app::lesson8::run() {
    SDL_Surface *background = NULL;
    SDL_Surface *message = NULL;

    initialize_screen();

    init_text();
    message = TTF_RenderText_Solid(font(), "The quick brown fox jumps over the lazy dog.", textcolor());
    background = load_image("background.png");

    apply_surface(0, 0, background);
    apply_surface(0, 150, message);

    flip();
    delay();
}

bool st::_app::lesson8::init_text() {
    if ( ! is_font_loaded() ) init_font();
    m_upmessage = TTF_RenderText_Solid( font(), "Up was pressed", textcolor() );
}

bool st::_app::lesson8::is_font_loaded() {
    return m_font != NULL;
}

bool st::_app::lesson8::init_font() {
    m_font = load_font("lazy.ttf",28);
}

TTF_Font* st::_app::lesson8::font() {
    return m_font;
}

SDL_Color st::_app::lesson8::textcolor() {
    return m_textcolor;
}

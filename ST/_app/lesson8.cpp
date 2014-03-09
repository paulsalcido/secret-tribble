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
    init_images();

    message = TTF_RenderText_Solid(font(), "The quick brown fox jumps over the lazy dog.", textcolor());
    // background = load_image("background.png");

    apply_surface(0, 0, m_background);

    start();
}

bool st::_app::lesson8::init_text() {
    if ( ! is_font_loaded() ) init_font();
    m_upmessage     = TTF_RenderText_Solid( font(), "Up was pressed",   textcolor() );
    m_downmessage   = TTF_RenderText_Solid( font(), "Down was pressed", textcolor() );
    m_leftmessage   = TTF_RenderText_Solid( font(), "Left was pressed", textcolor() );
    m_rightmessage  = TTF_RenderText_Solid( font(), "Right was pressed",textcolor() );
    return true;
}

bool st::_app::lesson8::init_images() {
    m_background = load_image("background.png");
    return true;
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

void st::_app::lesson8::event_handler(SDL_Event* event) {
    SDL_Surface* message = NULL;
    if ( event->type == SDL_KEYDOWN ) {
        switch( event->key.keysym.sym ) {
            case SDLK_UP:       message = m_upmessage;      break;
            case SDLK_DOWN:     message = m_downmessage;    break;
            case SDLK_LEFT:     message = m_leftmessage;    break;
            case SDLK_RIGHT:    message = m_rightmessage;   break;
        }
    }
    apply_message(message);
}

void st::_app::lesson8::apply_message(SDL_Surface* message) {
    if ( message != NULL ) {
        apply_surface(0, 0, m_background);
        apply_surface( 
                ( m_current_width  - message->w ) / 2,
                ( m_current_height - message->h ) / 2,
                message);
        flip();
    }
}

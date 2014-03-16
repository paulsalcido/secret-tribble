#include "_app/lesson10.h"

st::_app::lesson10::lesson10() { }

st::_app::lesson10::~lesson10() { }

void st::_app::lesson10::run() {
    initialize_screen();

    m_background = load_image("keystates-background.png");
    m_font = load_font("lazy.ttf", 28);

    apply_surface(0,0,m_background);

    m_upmessage     = TTF_RenderText_Solid( font(), "Up",   textcolor() );
    m_downmessage   = TTF_RenderText_Solid( font(), "Down", textcolor() );
    m_leftmessage   = TTF_RenderText_Solid( font(), "Left", textcolor() );
    m_rightmessage  = TTF_RenderText_Solid( font(), "Right",textcolor() );

    flip();
    start();
}

void st::_app::lesson10::event_handler(SDL_Event* event) {
    Uint8* keystates = SDL_GetKeyState( NULL );
    apply_surface(0,0,m_background);
    if ( keystates[SDLK_UP] )
        apply_surface(
                ( m_current_width       - m_upmessage->w )  / 2,
                ( m_current_height / 2  - m_upmessage->h )  / 2,
                m_upmessage);
    // There are better ways to do this math.
    if ( keystates[SDLK_DOWN] )
        apply_surface(
                ( m_current_width       - m_downmessage->w )/ 2,
                ( m_current_height / 2  - m_downmessage->w )/ 2
                    + m_current_height / 2,
                m_downmessage);
    if ( keystates[SDLK_RIGHT] )
        apply_surface(
                ( m_current_width / 2   - m_rightmessage->w)/ 2
                    + m_current_width / 2,
                ( m_current_height      - m_rightmessage->h)/ 2,
                m_rightmessage);
    if ( keystates[SDLK_LEFT] )
        apply_surface(
                ( m_current_width / 2   - m_leftmessage->w )/ 2,
                ( m_current_height      - m_rightmessage->h)/ 2,
                m_leftmessage);
    flip();
}

SDL_Color st::_app::lesson10::textcolor() {
    return m_textcolor;
}

TTF_Font* st::_app::lesson10::font() {
    return m_font;
}

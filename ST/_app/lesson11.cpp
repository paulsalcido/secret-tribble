#include "_app/lesson11.h"

st::_app::lesson11::lesson11() { }
st::_app::lesson11::~lesson11() { }

void st::_app::lesson11::run() {
    initialize_screen();

    m_font = load_font("lazy.ttf",28);
    m_background = load_image("keystates-background.png");
    init_messages();

    apply_surface(0,0,m_background);

    apply_surface(
            ( m_current_width - m_effect_message->w )  / 2,
            ( m_current_height - m_effect_message->h ) / 6,
            m_effect_message);

    apply_surface(
            ( m_current_width - m_play_pause_message->w )  / 2,
            ( m_current_height - m_play_pause_message->h ) / 2,
            m_play_pause_message);

    apply_surface(
            ( m_current_width - m_stop_message->w )  / 2,
            ( m_current_height - m_stop_message->h ) / 6 * 5,
            m_stop_message);

    flip();
    start();
}

void st::_app::lesson11::event_handler(SDL_Event* event) {
}

void st::_app::lesson11::init_messages() {
    m_effect_message =
        TTF_RenderText_Solid( font(),
            "Press 1, 2, 3, or 4 to play a sound effect",
            textcolor() );
    m_play_pause_message =
        TTF_RenderText_Solid( font(),
            "Press 9 to play or pause the music",
            textcolor() );
    m_stop_message =
        TTF_RenderText_Solid( font(),
            "Press 0 to stop the music",
            textcolor() );
}

SDL_Color st::_app::lesson11::textcolor() {
    return m_color;
}

TTF_Font* st::_app::lesson11::font() {
    return m_font;
}

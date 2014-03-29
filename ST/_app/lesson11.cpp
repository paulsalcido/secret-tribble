#include "_app/lesson11.h"

st::_app::lesson11::lesson11() {
    m_music = NULL;
    m_scratch = NULL;
    m_high = NULL;
    m_medium = NULL;
    m_low = NULL;
}

st::_app::lesson11::~lesson11() {
    free_media(m_music);
    free_media(m_scratch);
    free_media(m_high);
    free_media(m_medium);
    free_media(m_low);
}

void st::_app::lesson11::run() {
    initialize_screen("Monitor Music");

    m_font = load_font("lazy.ttf",28);
    m_background = load_image("keystates-background.png");
    init_messages();
    init_audio();

    init_sounds();

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

void st::_app::lesson11::init_sounds() {
    m_music     = load_music( "beat.wav" );
    m_scratch   = load_sound_chunk( "scratch.wav" );
    m_medium    = load_sound_chunk( "medium.wav" );
    m_low       = load_sound_chunk( "low.wav" );
    m_high      = load_sound_chunk( "high.wav" );
}

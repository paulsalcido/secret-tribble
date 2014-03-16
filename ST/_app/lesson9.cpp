#include "_app/lesson9.h"

st::_app::lesson9::lesson9() {
}

st::_app::lesson9::~lesson9() {
    if ( m_button != NULL ) {
        delete m_button;
        m_button = NULL;
    }
}

void st::_app::lesson9::run() {
    initialize_screen();

    m_button = new st::_app::button(170, 120, 320, 240);
    m_button->set_button_sheet(load_image("button.png"));

    clear_screen();
    m_button->show(this);

    flip();

    start();
}

void st::_app::lesson9::clear_screen() {
    SDL_FillRect(m_screen, &m_screen->clip_rect,
            SDL_MapRGB( m_screen->format, 0xFF, 0xFF, 0xFF ) );
}

void st::_app::lesson9::event_handler(SDL_Event*) {
}

#include "_app/lesson6.h"

st::_app::lesson6::lesson6() { }
st::_app::lesson6::~lesson6() { }

void st::_app::lesson6::run() {
    SDL_Surface* dots = NULL;

    SDL_Event event;
    initialize_screen();
    initialize_clips();

    SDL_FillRect( m_screen, &(m_screen->clip_rect), SDL_MapRGB( m_screen->format, 0xFF, 0xFF, 0xFF) );

    sdl_color_map* color_map = new sdl_color_map(0, 0xFF, 0xFF);
    dots = load_image("dots.png", true, color_map);

    apply_surface_clip( 0, 0, dots, &m_rect[0] );
    apply_surface_clip( 540, 0, dots, &m_rect[1] );
    apply_surface_clip( 0, 380, dots, &m_rect[2] );
    apply_surface_clip( 540, 380, dots, &m_rect[3] );

    flip();
    delay();
}

void st::_app::lesson6::initialize_clips() {
    m_rect[0].x = 0;
    m_rect[0].y = 0;
    m_rect[0].w = 100;
    m_rect[0].h = 100;

    m_rect[1].x = 100;
    m_rect[1].y = 0;
    m_rect[1].w = 100;
    m_rect[1].h = 100;

    m_rect[2].x = 0;
    m_rect[2].y = 100;
    m_rect[2].w = 100;
    m_rect[2].h = 100;

    m_rect[3].x = 100;
    m_rect[3].y = 100;
    m_rect[3].w = 100;
    m_rect[3].h = 100;
}

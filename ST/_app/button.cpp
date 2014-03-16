#include "_app/button.h"
#include <iostream>

st::_app::button::button(int x, int y, int w, int h) {
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    setup_clips();

    clip = &clips[ ST_APP_MOUSEOUT_CLIP ];
}

st::_app::button::~button() {
    if ( m_buttons != NULL ) {
        SDL_FreeSurface(m_buttons);
        m_buttons = NULL;
    }
}

void st::_app::button::handle_events(SDL_Event* event) {
    if      ( event->type == SDL_MOUSEMOTION )       handle_motion(event);
    else if ( event->type == SDL_MOUSEBUTTONDOWN )   handle_buttondown(event);
    else if ( event->type == SDL_MOUSEBUTTONUP )     handle_buttonup(event);
}

void st::_app::button::handle_motion(SDL_Event* event) {
    int x, y;
    x = event->motion.x;
    y = event->motion.y;

    if ( is_in_box(x,y) ) {
        clip = &clips[ST_APP_MOUSEOVER_CLIP];
    } else {
        clip = &clips[ST_APP_MOUSEOUT_CLIP];
    }
}

void st::_app::button::handle_buttondown(SDL_Event* event) {
    int x, y;
    x = event->motion.x;
    y = event->motion.y;

    if ( is_in_box(x,y) ) {
        clip = &clips[ST_APP_MOUSEDOWN_CLIP];
    }
}

void st::_app::button::handle_buttonup(SDL_Event* event) {
    int x, y;
    x = event->motion.x;
    y = event->motion.y;

    if ( is_in_box(x,y) ) {
        clip = &clips[ST_APP_MOUSEOVER_CLIP];
    }
}

bool st::_app::button::is_in_box(int x, int y) {
    return (
            ( x > box.x ) &&
            ( x < box.x + box.w ) &&
            ( y > box.y ) &&
            ( y < box.y + box.h )
        );
}

void st::_app::button::show(st::_app::sdl* screen) {
    if ( m_buttons != NULL ) {
        screen->apply_surface_clip(
                box.x,
                box.y,
                m_buttons,
                clip
            );
    }
}

void st::_app::button::setup_clips() {
    clips[ ST_APP_MOUSEOVER_CLIP ].x = 0;
    clips[ ST_APP_MOUSEOVER_CLIP ].y = 0;
    clips[ ST_APP_MOUSEOVER_CLIP ].w = 320;
    clips[ ST_APP_MOUSEOVER_CLIP ].h = 240;

    clips[ ST_APP_MOUSEOUT_CLIP ].x = 320;
    clips[ ST_APP_MOUSEOUT_CLIP ].y = 0;
    clips[ ST_APP_MOUSEOUT_CLIP ].w = 320;
    clips[ ST_APP_MOUSEOUT_CLIP ].h = 240;

    clips[ ST_APP_MOUSEDOWN_CLIP ].x = 0;
    clips[ ST_APP_MOUSEDOWN_CLIP ].y = 240;
    clips[ ST_APP_MOUSEDOWN_CLIP ].w = 320;
    clips[ ST_APP_MOUSEDOWN_CLIP ].h = 240;

    clips[ ST_APP_MOUSEUP_CLIP ].x = 320;
    clips[ ST_APP_MOUSEUP_CLIP ].y = 240;
    clips[ ST_APP_MOUSEUP_CLIP ].w = 320;
    clips[ ST_APP_MOUSEUP_CLIP ].h = 240;
}

void st::_app::button::set_button_sheet(SDL_Surface* surface) {
    // TODO:
    // This is going to make it super hard for memory managements
    // and is a very bad idea.  It will be something that I fix
    // in any real world system that I build, but for now, let's
    // finish this lesson.
    m_buttons = surface;
}

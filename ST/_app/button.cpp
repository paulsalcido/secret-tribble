#include "_app/button.h"

st::_app::button::button(int x, int y, int w, int h) {
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    clip = &clips[ ST_APP_MOUSEOUT_CLIP ];
}

st::_app::button::~button() { }

void st::_app::button::handle_events() { }
void st::_app::button::show() { }
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

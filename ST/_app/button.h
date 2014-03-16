#ifndef __ST_APP_BUTTON_H__
#define __ST_APP_BUTTON_H__

#include <_app/sdl.h>

#define ST_APP_MOUSEOVER_CLIP   0
#define ST_APP_MOUSEOUT_CLIP    1
#define ST_APP_MOUSEDOWN_CLIP   2
#define ST_APP_MOUSEUP_CLIP     3

namespace st {
    namespace _app {
        class button {
            public:
                button(int x, int y, int w, int h);
                ~button();

                void handle_events(SDL_Event*);
                void show(st::_app::sdl*);
                void setup_clips();
                bool is_in_box(int, int);
                void set_button_sheet(SDL_Surface*);
            protected:
                void handle_motion(SDL_Event*);
                void handle_buttondown(SDL_Event*);
            private:
                SDL_Surface* m_buttons = NULL;
                SDL_Rect box;
                SDL_Rect* clip;
                SDL_Rect clips[4];
        };
    }
}

#endif

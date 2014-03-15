#ifndef __ST_APP_BUTTON_H__
#define __ST_APP_BUTTON_H__

#include <SDL/SDL.h>

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

                void handle_events();
                void show();
                void setup_clips();
            private:
                SDL_Rect box;
                SDL_Rect* clip;
                SDL_Rect clips[4];
        };
    }
}

#endif

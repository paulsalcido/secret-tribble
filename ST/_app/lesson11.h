#ifndef __ST_LESSON11_H__
#define __ST_LESSON11_H__

#include "_app/sdl_poll.h"

namespace st {
    namespace _app {
        class lesson11: public st::_app::sdl_poll {
            public:
                lesson11();
                ~lesson11();

                void run();
            protected:
                void event_handler(SDL_Event*);
                void init_messages();
                TTF_Font* font();
                SDL_Color textcolor();

                SDL_Surface*    m_background;

                SDL_Surface     *m_effect_message,
                                *m_play_pause_message,
                                *m_stop_message;

                SDL_Color       m_color = { 0xFF, 0xFF, 0xFF };

                TTF_Font*       m_font;
        };
    }
}

#endif

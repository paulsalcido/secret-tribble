#ifndef __ST_LESSON10_H__
#define __ST_LESSON10_H__

#include "_app/sdl_poll.h"
#include "_app/button.h"

namespace st {
    namespace _app {
        class lesson10: public st::_app::sdl_poll {
            public:
                lesson10();
                ~lesson10();

                void run();
                TTF_Font* font();
                SDL_Color textcolor();
            protected:
                void event_handler(SDL_Event*);

                SDL_Surface*    m_background;
                TTF_Font*       m_font;
                SDL_Surface     *m_upmessage,
                                *m_downmessage,
                                *m_rightmessage,
                                *m_leftmessage;
                SDL_Color m_textcolor = { 255, 255, 255 };
        };
    }
}

#endif

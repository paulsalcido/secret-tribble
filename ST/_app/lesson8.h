#ifndef __ST_LESSON8_H__
#define __ST_LESSON8_H__

#include "_app/sdl_poll.h"

namespace st {
    namespace _app {
        class lesson8: public st::_app::sdl_poll {
            public:
                lesson8();
                ~lesson8();

                void run();
            protected:
                bool init_text();
                bool init_images();
                bool is_font_loaded();
                bool init_font();
                void event_handler(SDL_Event*);
                void apply_message(SDL_Surface*);

                /* It would be far more reasonable to map all of
                 * the text stuff, etc. to it's own class
                 * TODO */
                TTF_Font* font();
                SDL_Color textcolor();

                SDL_Surface *m_upmessage,
                    *m_downmessage,
                    *m_leftmessage,
                    *m_rightmessage,
                    *m_background;

                TTF_Font* m_font;

                SDL_Color m_textcolor = { 255, 255, 255 };
        };
    }
}

#endif

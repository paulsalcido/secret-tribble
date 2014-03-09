#ifndef __ST_SDL_POLL_H__
#define __ST_SDL_POLL_H__

#include "_app/sdl.h"

namespace st {
    namespace _app {
        class sdl_poll : public st::_app::sdl {
            public:
                sdl_poll();
                ~sdl_poll();

                void run();
            protected:
                void start();
                virtual void event_handler(SDL_Event*) = 0;

                bool m_quit = false;
        };
    }
}

#endif

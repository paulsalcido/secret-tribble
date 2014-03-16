#ifndef __ST_LESSON9_H__
#define __ST_LESSON9_H__

#include "_app/sdl_poll.h"
#include "_app/button.h"

namespace st {
    namespace _app {
        class lesson9: public st::_app::sdl_poll {
            public:
                lesson9();
                ~lesson9();

                void run();
                void clear_screen();
            protected:
                void event_handler(SDL_Event*);

                st::_app::button* m_button = NULL;
        };
    }
}

#endif

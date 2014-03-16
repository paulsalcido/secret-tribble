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
            protected:
                void event_handler(SDL_Event*);
        };
    }
}

#endif

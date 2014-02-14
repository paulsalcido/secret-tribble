#ifndef __ST_LESSON6_H__
#define __ST_LESSON6_H__

#include "_app/sdl.h"

namespace st {
    namespace _app {
        class lesson6: public st::_app::sdl {
            public:
                lesson6();
                ~lesson6();

                void run();
            protected:
                void initialize_clips();

                SDL_Rect m_rect[4];
        };
    }
}

#endif

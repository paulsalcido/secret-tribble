#ifndef __ST_APP_LESSON2__
#define __ST_APP_LESSON2__

#include "./sdl.h"
#include <string>
#include "SDL/SDL.h"

namespace st {
    namespace _app {
        class lesson2: public st::_app::sdl {
            public:
                lesson2();
                ~lesson2();

                void run();
            protected:
        };
    }
}

#endif

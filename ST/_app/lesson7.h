#ifndef __ST_LESSON7_H__
#define __ST_LESSON7_H__

#include "_app/sdl.h"

namespace st {
    namespace _app {
        class lesson7: public st::_app::sdl {
            public:
                lesson7();
                ~lesson7();

                void run();
            protected:
                bool init();
        };
    }
}

#endif

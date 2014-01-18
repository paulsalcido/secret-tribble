#ifndef _ST_APP_SDL_H_
#define _ST_APP_SDL_H_

#include "../app.h"
#include "SDL/SDL.h"

namespace st {
    namespace _app {
        class sdl: public app {
            public: 
                sdl();
                ~sdl();

            protected:
                bool init();
                bool finish();

                // This will probably be a bad decision!
                SDL_Surface* m_screen;
        };
    }
}

#endif

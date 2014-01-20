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

                void run();
                bool flip();
                void delay(int del = 2000);
                bool initialize_screen(std::string caption = "no name");
                void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination = NULL);
                void free_surface(SDL_Surface* surface);

                SDL_Surface* load_image(std::string name, bool optimize = true);
                SDL_Surface* load_bitmap(std::string name, bool optimize = true);
            protected:
                bool init();
                bool finish();
                SDL_Surface* _load_image(std::string name, bool optimize = true, bool sdl_image = true);

                // This will probably be a bad decision!
                SDL_Surface* m_screen;
        };
    }
}

#endif

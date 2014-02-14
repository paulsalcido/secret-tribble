#ifndef _ST_APP_SDL_H_
#define _ST_APP_SDL_H_

#include "../app.h"
#include "SDL/SDL.h"

namespace st {
    namespace _app {
        class sdl_color_map {
            public:
                sdl_color_map(int r = 0, int g = 0, int b = 0): m_r(r), m_g(g), m_b(b) { }
                ~sdl_color_map() { }

                int r() { return m_r; }
                int g() { return m_g; }
                int b() { return m_b; }

                Uint32 color_map(SDL_Surface* surface) {
                    return SDL_MapRGB(surface->format, r(), g(), b());
                }

                void set_color_key(SDL_Surface* surface) {
                    SDL_SetColorKey(surface, SDL_SRCCOLORKEY, color_map(surface));
                }
            protected:
                int m_r;
                int m_g;
                int m_b;
        };

        class sdl: public app {
            public: 
                sdl();
                ~sdl();

                void run();
                bool flip();
                void delay(int del = 2000);
                bool initialize_screen(std::string caption = "no name",
                        int width = 640,
                        int height = 480,
                        int bpp = 32);
                void apply_surface_clip(
                        int x,
                        int y,
                        SDL_Surface* source,
                        SDL_Rect* clip = NULL);
                void apply_surface(
                        int x,
                        int y,
                        SDL_Surface* source,
                        SDL_Surface* destination = NULL,
                        SDL_Rect* clip = NULL);
                void free_surface(SDL_Surface* surface);

                // TODO: Hide all of this SDL information behind internal classes.
                // I'll do it in big changesets later, why not?  Let's just get this
                // done.
                SDL_Surface* load_image(std::string name, bool optimize = true, sdl_color_map* color_map = NULL);
                SDL_Surface* load_bitmap(std::string name, bool optimize = true, sdl_color_map* color_map = NULL);
            protected:
                bool init();
                bool finish();
                SDL_Surface* _load_image(std::string name, bool optimize, bool sdl_image, sdl_color_map*);

                // This will probably be a bad decision!
                SDL_Surface* m_screen;
        };
    }
}

#endif

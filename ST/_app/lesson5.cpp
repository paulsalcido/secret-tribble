#include "_app/lesson5.h"

st::_app::lesson5::lesson5() { }
st::_app::lesson5::~lesson5() { }

void st::_app::lesson5::run() {
    initialize_screen();
    // Boy, I miss hash style sub calls.
    sdl_color_map* color_map = new sdl_color_map(0, 0xFF, 0xFF);
    SDL_Surface* person = load_image("looking-the-foo.png", true, color_map);
    delete color_map;
    SDL_Surface* background = load_image("sunny-day.png");
    apply_surface(0, 0, background);
    apply_surface(240, 190, person);
    flip();
    delay();
    free_surface(person);
    free_surface(background);
}

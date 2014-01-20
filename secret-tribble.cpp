#include <iostream>
#include "ST/app.h"
#include "ST/media.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    st::app *main_app = st::app::build_app(argc > 1 ? argv[1] : "sdl");
    std::cout << st::media::default_media_path() << std::endl;
    main_app->run();
    delete main_app;
    return 0;
}

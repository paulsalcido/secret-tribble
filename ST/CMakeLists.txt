include (FindPkgConfig)
pkg_search_module (SDL REQUIRED sdl)
include_directories(${SDL_INCLUDE_DIRS})

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/ST")

add_library(ST
    app.cpp
    _app/sdl.cpp
    _app/lesson2.cpp
    _app/lesson3.cpp
    _app/lesson4.cpp
    _app/lesson5.cpp
    _app/lesson6.cpp
    _app/lesson7.cpp
    _app/lesson8.cpp
    _app/lesson9.cpp
    _app/lesson10.cpp
    _app/lesson11.cpp
    _app/button.cpp
    _app/sdl_poll.cpp
    media.cpp)

target_link_libraries(ST ${SDL_LIBRARIES} SDL_image SDL_ttf SDL_mixer)

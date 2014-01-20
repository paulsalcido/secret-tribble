include (FindPkgConfig)
pkg_search_module (SDL REQUIRED sdl)
include_directories(${SDL_INCLUDE_DIRS})

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/ST")

add_library(ST app.cpp media.cpp _app/sdl.cpp _app/lesson2.cpp _app/lesson3.cpp _app/lesson4.cpp)
target_link_libraries(ST ${SDL_LIBRARIES} SDL_image)

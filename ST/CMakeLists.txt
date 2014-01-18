include (FindPkgConfig)
pkg_search_module (SDL REQUIRED sdl)
include_directories(${SDL_INCLUDE_DIRS})

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/ST")

add_library(ST app.cpp _app/sdl.cpp)
target_link_libraries(ST ${SDL_LIBRARIES})

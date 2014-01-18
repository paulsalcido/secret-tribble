cmake_minimum_required (VERSION 2.6)
project (secret-tribble)
include (FindPkgConfig)
pkg_search_module (SDL REQUIRED sdl)
include_directories(${SDL_INCLUDE_DIRS})
# target_link_libraries(${SDL_LIBRARIES})

add_executable(secret-tribble secret-tribble.cpp)
target_link_libraries(secret-tribble ${SDL_LIBRARIES})

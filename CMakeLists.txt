cmake_minimum_required (VERSION 2.6)
project (secret-tribble)

#include (FindPkgConfig)
#pkg_search_module (SDL REQUIRED sdl)
#include_directories(${SDL_INCLUDE_DIRS})

#include_directories("${PROJECT_BINARY_DIR}")
#include_directories("${PROJECT_BINARY_DIR}/ST")

add_subdirectory(ST)

add_executable(secret-tribble secret-tribble.cpp)
target_link_libraries(secret-tribble ${SDL_LIBRARIES} ST)

cmake_minimum_required (VERSION 2.6)
project (secret-tribble)

set(CMAKE_CXX_FLAGS "--std=c++11")

add_subdirectory(ST)

add_executable(secret-tribble secret-tribble.cpp)
target_link_libraries(secret-tribble ${SDL_LIBRARIES} ST)

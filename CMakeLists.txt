cmake_minimum_required(VERSION 3.20)

project(psx_educational_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 CONFIG REQUIRED)

add_executable(psx_engine
    src/main.cpp
)

target_include_directories(psx_engine PRIVATE
    src
)

target_link_libraries(psx_engine PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
)


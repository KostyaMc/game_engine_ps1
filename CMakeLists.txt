cmake_minimum_required(VERSION 3.20)

project(psx_educational_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 CONFIG REQUIRED)

add_library(psx_core STATIC
    src/core/color.cpp
    src/core/framebuffer.cpp
    src/engine/application.cpp
    src/math/vec2.cpp
    src/math/vec3.cpp
)

target_include_directories(psx_core PUBLIC
    src
)

target_link_libraries(psx_core PUBLIC
    SDL2::SDL2
)

add_executable(psx_engine
    src/main.cpp
)

target_link_libraries(psx_engine PRIVATE
    psx_core
    SDL2::SDL2main
)

add_executable(psx_math_tests
    tests/math_tests.cpp
)

target_link_libraries(psx_math_tests PRIVATE
    psx_core
)

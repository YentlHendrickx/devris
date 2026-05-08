cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

add_executable(Tetris
    src/main.cpp
    src/game.cpp
    src/renderer.cpp
    src/input.cpp
    src/piece.cpp
    src/board.cpp
)

target_link_libraries(Tetris ${SDL2_LIBRARIES})

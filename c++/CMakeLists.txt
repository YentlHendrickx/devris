cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

# Define the path to SDL2
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL2")

include_directories(${SDL2_DIR}/include ${CMAKE_SOURCE_DIR}/include)
link_directories(${SDL2_DIR}/lib/x64)

add_executable(Tetris
    src/main.cpp
    src/game.cpp
    src/renderer.cpp
    src/input.cpp
    src/piece.cpp
    src/board.cpp
)

target_link_libraries(Tetris SDL2 SDL2main)

# Copy the SDL2.dll to the build directory
add_custom_command(TARGET Tetris POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL2_DIR}/SDL2.dll"
    $<TARGET_FILE_DIR:Tetris>)

# Tetris in C++ using SDL2

## Overview
This repository is dedicated to building a Tetris game using C++ and SDL2. The goal is to create a fully functional, visually appealing, and extensible version of Tetris. While the initial implementation is in C++ with SDL2, the project is designed to be adaptable for implementations in other languages in the future.

## Features
- **Classic Tetris Gameplay**: Implements traditional Tetris mechanics.
- **Modern SDL2 Graphics**: Uses SDL2 for rendering and handling user input.
- **Modular Codebase**: Easily extendable for future improvements or ports to other languages.
- **Cross-Platform**: Runs on Linux, Windows, and macOS.

## Requirements
- C++17 or later
- SDL2 library

### Install SDL2
#### Debian/Ubuntu
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```
#### Arch Linux
```bash
sudo pacman -S sdl2 sdl2_image sdl2_ttf
```
#### macOS (Homebrew)
```bash
brew install sdl2 sdl2_image sdl2_ttf
```

## Building and Running
### Compile with Makefile
```bash
make
```
### Run the Game
```bash
./tetris
```
### Clean Build Files
```bash
make clean
```

## Future Plans
- Implement AI for automated gameplay.
- Add multiplayer support.
- Explore implementations in Python, Rust, or JavaScript.

## Contributions
Contributions are welcome! If you would like to add support for another language or improve the existing implementation, feel free to submit a pull request.

## License
This project is open-source under the MIT License.


#include<game.h>
#include<iostream>

int main(int argc, char* argv[]) {
    Game game;
    if (!game.init()) {
        std::cout << "Failed to initialize game" << std::endl;
        return -1;
    }
    
    std::cout << "Game initialized" << std::endl;
    
    game.run();
    
    // Normally not needed, but SDL is a bit special
    return 0;
}
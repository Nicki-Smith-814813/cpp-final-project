#include <iostream>
#include "game.h"

int main() {
    std::cout << "Welcome to Hadestown: The RPG!\n\n";

    try {
        Game game;
        game.start();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

    

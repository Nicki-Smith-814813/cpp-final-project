#include <iostream>
#include <cstdlib> // For srand()
#include <ctime>   // For time()
#include "game.h"
#include "utils.h"
#include "settings.h"

int main() {
    srand(time(0));
    std::cout << "Welcome to Hadestown: The RPG!\n\n";
    dramaticPause(1000);
    std::cout << "Tip: Type your answers carefully — the Fates are watching...\n\n";

    try {
        Game game;
        game.showMainMenu();  // Call the new menu
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

    

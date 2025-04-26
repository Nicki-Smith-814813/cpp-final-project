#include <iostream>
#include "characters.h"

void Character::displayStats() {
    std::cout << "Name: " << name << "\n";
    std::cout << "Faith: " << faith << "\n";
    std::cout << "Trust: " << trust << "\n";
}

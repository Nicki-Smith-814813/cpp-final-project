#include <iostream>
#include "characters.h"

void Character::displayStats() {
    std::cout << "Name: " << name << "\n";
    std::cout << "Faith: " << faith << "\n";
    std::cout << "Trust: " << trust << "\n";
}

float faith = 100.0f;  // Initial value for faith
float trust = 0.0f;  // Initial value for trust
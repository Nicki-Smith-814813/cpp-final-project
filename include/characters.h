// characters.h
#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>

struct Character {
    std::string name;
    int faith;
    int trust;

    void displayStats();
};



#endif // CHARACTERS_H

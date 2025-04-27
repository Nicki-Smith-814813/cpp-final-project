#ifndef UTILS_H
#define UTILS_H

#include <string>

enum class Speaker {
    Narrator,
    Hades,
    Persephone,
    Orpheus,
    Hermes,
    Fates,
    Eurydice
};

void displayDialogue(const std::string& dialogue, Speaker speaker = Speaker::Narrator);
void displayChoice(const std::string& prompt, const std::string choices[], int numChoices);
void clearScreen();
void pause();

#endif

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

void displayDialogue(const std::string& message, int delayMs = 30); // narration
void displaySpeakerDialogue(const std::string& speaker, const std::string& message);
void displayChoice(const std::string& prompt, const std::string choices[], int numChoices);
void dramaticPause(int ms);
void pause();

#pragma once
#include "characters.h"

void saveGame(const Character& player, const std::string& filename);
bool loadGame(Character& player, const std::string& filename);

void autosave(const Character& player);

int getValidatedInput(int min, int max);

#endif

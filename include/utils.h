#ifndef UTILS_H
#define UTILS_H

#include <iostream>         // for std::cout and std::cin
#include <string>           // for std::string
#include <limits>           // for std::numeric_limits
#include <algorithm>        // for std::max, std::min

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

// Reusable templated input function
template <typename T>
T getValidatedInput(const string& prompt, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
    T input;
    bool valid = false;
    while (!valid) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
        } else {
            valid = true;
        }
    }
    return input;
}


void clearScreen();
void setSceneTheme(const std::string& colorCode, const std::string& asciiArtFile);

void printAsciiArt(const std::string& filename);


#endif

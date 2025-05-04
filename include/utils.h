#ifndef UTILS_H
#define UTILS_H

#include <iostream>         // for std::cout and std::cin
#include <string>           // for std::string
#include <limits>           // for std::numeric_limits
#include <algorithm>        // for std::max, std::min
#include <vector>
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
std::string wrapText(const std::string& input, int width = 80);

void displayChoice(const std::string& prompt, const std::string choices[], int numChoices);
void dramaticPause(int ms);
void pause();

#pragma once
#include "characters.h"

void saveGame(const Character& player, const std::string& filename);
bool loadGame(Character& player, const std::string& filename);

void autosave(const Character& player);

// Reusable templated input function
using namespace std;

template <typename T>
T getValidatedInput(const string& prompt, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()) {
    T input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            if (input >= min && input <= max) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
                return input;
            } else {
                cout << "Please choose a valid option (" << min << "-" << max << ").\n";
            }
        } else {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush invalid input
            cout << "Invalid input. Try again.\n";
        }
    }
}




void clearScreen();

void setSceneTheme(const std::string& colorCode, const std::string& asciiArtFile);

void printAsciiArt(const std::string& filename);

std::string getRandomResponse(const std::vector<std::string>& responses);

#endif

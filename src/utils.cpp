#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <cstdlib>
#include <fstream>

using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string DEEP_CRIMSON = "\033[38;2;153;0;0m";
const string BRIGHT_GREEN = "\033[38;2;0;255;0m";
const string GOLD = "\033[38;2;255;215;0m";
const string WHITE = "\033[97m";
const string DEEP_BLUE = "\033[38;2;0;0;153m";
const string SILVER = "\033[38;2;192;192;192m";

string getSpeakerColor(Speaker speaker) {
    switch (speaker) {
        case Speaker::Hades: return DEEP_CRIMSON;
        case Speaker::Persephone: return BRIGHT_GREEN;
        case Speaker::Orpheus: return GOLD;
        case Speaker::Hermes: return WHITE;
        case Speaker::Fates: return DEEP_BLUE;
        case Speaker::Eurydice: return SILVER;
        default: return WHITE;
    }
}

string getSpeakerName(Speaker speaker) {
    switch (speaker) {
        case Speaker::Hades: return "Hades";
        case Speaker::Persephone: return "Persephone";
        case Speaker::Orpheus: return "Orpheus";
        case Speaker::Hermes: return "Hermes";
        case Speaker::Fates: return "The Fates";
        case Speaker::Eurydice: return "Eurydice";
        default: return "";
    }
}

void displayDialogue(const string& dialogue, Speaker speaker) {
    string color = getSpeakerColor(speaker);
    string name = getSpeakerName(speaker);

    if (!name.empty()) {
        cout << color << name << ":" << RESET << "\n";
    }

    // Simulate slight "shaking" for dramatic tension
    for (char c : dialogue) {
        cout << color << c << RESET << flush;
        this_thread::sleep_for(chrono::milliseconds(30));

        // Random tiny horizontal shake (space insertions)
        if (rand() % 50 == 0) {
            cout << ' ' << flush;
        }
    }
    cout << "\n\n";
    pause();
}

void displayChoice(const string& prompt, const string choices[], int numChoices) {
    cout << prompt << "\n";
    for (int i = 0; i < numChoices; ++i) {
        cout << i + 1 << ". " << choices[i] << "\n";
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



void saveGame(const Character& player, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << player.name << "\n"
                << player.faith << "\n"
                << player.trust << "\n";
        outFile.close();
    } else {
        std::cout << "Error saving game.\n";
    }
}

bool loadGame(Character& player, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        getline(inFile, player.name);
        inFile >> player.faith
               >> player.trust;
        inFile.close();
        return true;
    } else {
        std::cout << "No save file found.\n";
        return false;
    }
}



int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Enter choice (" << min << "-" << max << "): ";
        std::cin >> choice;
        if (std::cin.fail() || choice < min || choice > max) {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return choice;
        }
    }
}

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

void displayDialogue(const string& message, int delayMs) {
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

void displaySpeakerDialogue(const string& speaker, const string& message) {
    if (speaker == "Hermes") {
        cout << "\033[37m" << speaker << ": " << message << "\033[0m" << endl;
    } else if (speaker == "Hades") {
        cout << "\033[31m" << speaker << ": " << message << "\033[0m" << endl;
    } else if (speaker == "Persephone") {
        cout << "\033[32m" << speaker << ": " << message << "\033[0m" << endl;
    } else if (speaker == "Orpheus") {
        cout << "\033[33m" << speaker << ": " << message << "\033[0m" << endl;
    } else if (speaker == "Fates") {
        cout << "\033[34m" << speaker << ": " << message << "\033[0m" << endl;
    } else if (speaker == "Eurydice") {
        cout << "\033[36m" << speaker << ": " << message << "\033[0m" << endl;
    } else {
        cout << speaker << ": " << message << endl;
    }
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

void dramaticPause(int milliseconds = 1000) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    clearScreen();
}


void pause() {
    cout << "\n(Press Enter to continue...)\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



void saveGame(const Character& player, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open()) {
        size_t nameLength = player.name.size();
        outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength)); // save length
        outFile.write(player.name.c_str(), nameLength);                                // save actual name

        outFile.write(reinterpret_cast<const char*>(&player.faith), sizeof(player.faith));
        outFile.write(reinterpret_cast<const char*>(&player.trust), sizeof(player.trust));
        outFile.close();
    } else {
        std::cout << "Error saving game.\n";
    }
}

bool loadGame(Character& player, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        size_t nameLength = 0;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

        player.name.resize(nameLength);
        inFile.read(&player.name[0], nameLength);

        inFile.read(reinterpret_cast<char*>(&player.faith), sizeof(player.faith));
        inFile.read(reinterpret_cast<char*>(&player.trust), sizeof(player.trust));
        inFile.close();
        return true;
    } else {
        std::cout << "No save file found.\n";
        return false;
    }
}


void autosave(const Character& player) {
    saveGame(player, "savefile.dat");
    std::cout << "(Game autosaved.)\n";
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

#define RESET   "\033[0m"
#define RED     "\033[41m"
#define GREEN   "\033[42m"
#define BLUE    "\033[44m"
#define BLACK   "\033[40m"
#define WHITE   "\033[47m"
#define YELLOW  "\033[43m"
#define CYAN    "\033[46m"

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape to clear screen and reset cursor
}

void printAsciiArt(const std::string& filename) {
    std::ifstream file("assets/ascii/" + filename);
    if (!file) {
        std::cerr << "Error: Could not load ASCII art: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
}


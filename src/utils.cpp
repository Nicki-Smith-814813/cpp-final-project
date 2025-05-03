#include "utils.h"
#include "settings.h"  // for textSpeed
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <cstdlib>
#include <fstream>
#include <sstream>

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

const int WRAP_WIDTH = 80; // Set your preferred wrap width here

string wrapText(const string& input, int width) {
    istringstream words(input);
    ostringstream wrapped;
    string word;
    int lineLength = 0;

    while (words >> word) {
        if (lineLength + word.length() + 1 > width) {
            wrapped << "\n";
            lineLength = 0;
        }
        if (lineLength != 0) {
            wrapped << " ";
            lineLength++;
        }
        wrapped << word;
        lineLength += word.length();
    }
    return wrapped.str();
}

void displayDialogue(const std::string& message, int delayMs) {
    string wrapped = wrapText(message, WRAP_WIDTH);
    for (char c : wrapped) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

void displayDialogue(const std::string& message) {
    displayDialogue(message, textSpeed);
}

void displaySpeakerDialogue(const string& speaker, const string& message) {
    string color;
    if (speaker == "Hermes") color = "\033[37m";
    else if (speaker == "Hades") color = "\033[31m";
    else if (speaker == "Persephone") color = "\033[32m";
    else if (speaker == "Orpheus") color = "\033[33m";
    else if (speaker == "Fates") color = "\033[34m";
    else if (speaker == "Eurydice") color = "\033[36m";

    string full = speaker + ": " + message;
    string wrapped = wrapText(full, WRAP_WIDTH);

    if (disableColor) {
        displayDialogue(wrapped, textSpeed);
    } else {
        cout << color;
        displayDialogue(wrapped, textSpeed);
        cout << RESET;
    }
}





void displayChoice(const string& prompt, const string choices[], int numChoices) {
    cout << prompt << "\n";
    for (int i = 0; i < numChoices; ++i) {
        cout << i + 1 << ". " << choices[i] << "\n";
    }
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


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "scenes/faithSystem.h"
#include "characters.h"
#include "utils.h"
using namespace std;

void increaseFaith(Character& player, float amount) {
    player.faith += amount;
    if (player.faith > 100.0f) player.faith = 100.0f;
}

void decreaseFaith(Character& player, float amount) {
    player.faith -= amount;
    if (player.faith < 0.0f) player.faith = 0.0f;
}
// Function to handle Fates' questions
void mythQuestions() {
    int correctAnswers = 0;

    cout << "The Fates swirl around you, their voices sharp and mocking.\n";
    cout << "'Let's see if you truly understand the world you're trying to change,' they sneer.\n";
    
    // Question 1
    cout << "Who was the hero that completed the Twelve Labors?\n";
    cout << "1. Perseus\n";
    cout << "2. Heracles\n";
    cout << "3. Theseus\n";
    cout << "Enter your answer (1, 2, or 3): ";
    int answer;
    cin >> answer;
    if (answer == 2) {
        cout << "Correct! Heracles did complete the Twelve Labors.\n";
        correctAnswers++;
        faith += 10;  // Gain faith for the correct answer
    } else {
        cout << "Wrong! The correct answer is Heracles.\n";
        faith -= 10;  // Lose faith for the wrong answer
    }

    // Question 2
    cout << "Who turned into a spider after being defeated by Athena in a weaving contest?\n";
    cout << "1. Medusa\n";
    cout << "2. Arachne\n";
    cout << "3. Hera\n";
    cout << "Enter your answer (1, 2, or 3): ";
    cin >> answer;
    if (answer == 2) {
        cout << "Correct! Arachne was turned into a spider.\n";
        correctAnswers++;
        faith += 10;
    } else {
        cout << "Wrong! The correct answer is Arachne.\n";
        faith -= 10;
    }

    // Question 3
    cout << "Who was cursed to turn everything they touched into gold?\n";
    cout << "1. Midas\n";
    cout << "2. King Minos\n";
    cout << "3. Persephone\n";
    cout << "Enter your answer (1, 2, or 3): ";
    cin >> answer;
    if (answer == 1) {
        cout << "Correct! King Midas turned everything he touched into gold.\n";
        correctAnswers++;
        faith += 10;
    } else {
        cout << "Wrong! The correct answer is Midas.\n";
        faith -= 10;
    }

    // End the question section
    if (correctAnswers >= 2) {
        displayDialogue("The Fates seem to soften their stance, impressed with your knowledge.");
    } else {
        displayDialogue("The Fates sneer. 'Not enough knowledge to change the fate of others.'");
    }

    cout << "Your current faith level: " << faith << "%\n";
}

// Function to simulate the hades says challenge
bool hadesSaysChallenge() {
    cout << "\nHades' eyes gleam. \"Let's see if you can remember, mortal.\"\n";
    cout << "He begins issuing commands, one after another...\n\n";

    srand(time(0)); // Seed random generator

    vector<string> possibleCommands = {
        "Bow",
        "Clap",
        "Stomp",
        "Spin",
        "Touch your toes",
        "Jump",
        "Raise your hands",
        "Kneel"
    };

    vector<string> sequence;
    int rounds = 3; // How many commands to memorize (you can increase this for harder)

    // Generate the sequence
    for (int i = 0; i < rounds; ++i) {
        int index = rand() % possibleCommands.size();
        sequence.push_back(possibleCommands[index]);
        cout << "Hades says: " << possibleCommands[index] << endl;
    }

    cout << "\nNow, repeat the commands exactly, one at a time.\n";
    cout << "(Type your responses exactly: example -> Bow)\n\n";

    // Player must repeat the sequence
    for (int i = 0; i < rounds; ++i) {
        cout << "Command #" << (i+1) << ": ";
        string response;
        getline(cin >> ws, response); // Clean input handling

        if (response != sequence[i]) {
            cout << "Hades frowns darkly. \"WRONG.\"\n";
            return false;
        }
    }

    cout << "Hades chuckles, impressed. \"You have a sharp mind after all.\"\n";
    return true;
}

bool musicalGame() {
    string playerInput;
    int score = 0;

    // A simple sequence of notes (or rhythm) for Orpheus to follow
    string notes[] = {"Do", "Re", "Mi", "Fa", "So"};
    int numNotes = 5;

    // Seed the random number generator
    srand(time(0));

    // Start the musical game
    displayDialogue("Hades leans back, watching Orpheus with a calculating gaze.\n");
    displayDialogue("'Alright, Orpheus,' Hades says, 'Let’s see if you can truly sing your way out of this place. Follow the sequence and show me you're worthy of leaving Hadestown.'\n");

    // Generate a random sequence of notes (a simple melody)
    int melody[3];
    for (int i = 0; i < 3; ++i) {
        melody[i] = rand() % numNotes;  // Randomly select notes
    }

    // Display the melody for the player to follow
    displayDialogue("Here’s the melody. Follow it.\n");
    for (int i = 0; i < 3; ++i) {
        cout << notes[melody[i]] << " ";
    }
    cout << "\n";

    // Ask the player to repeat the melody
    cout << "Enter the melody sequence (Do, Re, Mi, Fa, So): ";
    for (int i = 0; i < 3; ++i) {
        cin >> playerInput;
        
        // Check if player’s input matches the generated melody
        if (playerInput == notes[melody[i]]) {
            score++;
        } else {
            displayDialogue("You missed a note! Try again.\n");
            return false;  // Player failed, return false
        }
    }

    // If the player matches the entire melody
    if (score == 3) {
        displayDialogue("'Well done, Orpheus,' Hades says, clearly impressed. 'You’ve earned it. You and Eurydice may leave Hadestown.'\n");
        return true;  // Player succeeded
    }

    return false;  // Player failed
}


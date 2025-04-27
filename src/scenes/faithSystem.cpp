#include "faithSystem.h"
#include "characters.h"
#include "utils.h"
#include <string>

using namespace std;

float faith = 100.0f; // starting faith

void increaseFaith(float amount) {
    faith += amount;
    if (faith > 100.0f) faith = 100.0f;
}

void decreaseFaith(float amount) {
    faith -= amount;
    if (faith < 0.0f) faith = 0.0f;
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
    string playerInput;
    int score = 0;

    // Commands for the hades says challenge
    string commands[] = {
        "Hades says touch your nose.",
        "Touch your toes.",
        "Hades says clap your hands.",
        "Spin around.",
        "Hades says raise your right hand.",
        "Count to ten.",
        "Hades says dance.",
        "Recite a poem.",
        "Hades says sing me a song."
    };

    // Number of hades says commands to give
    int numCommands = 9;

    // Seed the random number generator
    srand(time(0));

    // Hades says game loop
    for (int i = 0; i < numCommands; ++i) {
        int randCommand = rand() % 9; // Choose a random command

        // If the command is "Hades says" or not
        if (randCommand % 2 == 0) { // Even numbers are "Hades says" commands
            displayDialogue(commands[randCommand]);  // Display the command

            // Get player's input (responding "yes" or "no")
            cout << "Did you follow the command? (yes/no): ";
            cin >> playerInput;

            // Check if player responded correctly
            if (playerInput == "yes") {
                score++;
            } else {
                displayDialogue("You failed to follow the command!");
            }
        } else {
            displayDialogue("Do not do anything. (No Hades says!)");

            cout << "Did you follow the command? (yes/no): ";
            cin >> playerInput;

            // If the player does it anyway, they fail
            if (playerInput == "yes") {
                displayDialogue("You were supposed to ignore this command!");
            }
        }
    }

    // Determine success based on the number of correct responses
    if (score == 3) {
        displayDialogue("You successfully followed Hades' commands!");
        return true;  // Player wins
    } else {
        displayDialogue("You failed to follow the commands correctly.");
        return false;  // Player loses
    }
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


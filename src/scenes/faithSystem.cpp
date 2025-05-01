#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
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
void mythQuestions(Character& player) {

    printAsciiArt("fates.txt");
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
        displaySpeakerDialogue("Fates","The Fates sneer. 'Not enough knowledge to change the fate of others.'");
    }

    cout << "Your current faith level: " << faith << "%\n";
}

// Function to simulate the hades says challenge
bool hadesSaysChallenge() {
    cout << "\nHades' eyes gleam. \"Let's see if you can remember, mortal.\"\n";
    cout << "He begins issuing commands, one after another...\n\n";


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
    int rounds = 5; // How many commands to memorize

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
//Musical challenge
bool musicalGame(Character& player, bool isRetry, int difficultyLevel) 
{
    if (isRetry) {
        displaySpeakerDialogue("Hades", "You dare try again, boy? The melody grows longer...");
    } else {
        displaySpeakerDialogue("Hades", "Let's see if you can truly sing your way out of this place.");
    }

    int melodyLength;
    if (difficultyLevel == 1) {
        melodyLength = 5;
    } else if (difficultyLevel == 2) {
        melodyLength = 7;
        displaySpeakerDialogue("Fates", "*The melody grows longer... the threads twist tighter...*");
    } else {
        melodyLength = 10;
        displaySpeakerDialogue("Fates", "*The melody is endless, boy... Can you even hear it anymore?*");
    }

    string playerInput;
    int score = 0;

    string notes[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Ti"};
    int numNotes = 7;

    

    displayDialogue("Hades leans back, watching Orpheus with an iron gaze...");
    displaySpeakerDialogue("Hades", "Here’s the melody. Listen carefully.\n");

    vector<string> melody;

    // Generate and show melody with erasing effect
    for (int i = 0; i < melodyLength; ++i) {
        int index = rand() % numNotes;
        melody.push_back(notes[index]);

        cout << melody[i] << " " << flush;
        dramaticPause(500);

        cout << "\r      \r" << flush;
        dramaticPause(300);
    }
    cout << "\n\n";
    cout << "\n\n";

    // IMPORTANT: clear input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Player must repeat the melody
    cout << "Enter the melody sequence (type: Do, Re, Mi, Fa, So, La, Ti):\n";
    for (int i = 0; i < melodyLength; ++i) {
        cin >> playerInput;
        if (playerInput == melody[i]) {
            score++;
        } else {
            displaySpeakerDialogue("Fates", "*You falter... the thread snaps.*");
            return false; // fail immediately
        }
    }
    if (score == melodyLength) {
        displaySpeakerDialogue("Hades", "Impressive. Your memory serves you well.");
        return true;
    }

    return false; // fallback, shouldn't normally hit
}

// --------------------------------
// Randomized Fate Taunt Function
// --------------------------------
void randomizedFatesTaunt(const Character& player) 
{
    vector<string> strongFaithTaunts = {
        "*Strong thread yet, little songbird... but can you hold it?*",
        "*A golden thread, spun tight... but even gold can snap.*",
        "*You shine still... will you survive the loom?*"
    };

    vector<string> mediumFaithTaunts = {
        "*The thread frays... one wrong note and you're gone.*",
        "*Your fate hangs by a thread, boy.*",
        "*The loom trembles. Your song grows thin.*"
    };

    vector<string> weakFaithTaunts = {
        "*Ha! Barely a thread left! One pull and you fall apart.*",
        "*A breath could scatter you to dust.*",
        "*The song is almost over. One wrong note, and you're lost forever.*"
    };

    if (player.faith >= 70.0f) {
        int idx = rand() % strongFaithTaunts.size();
        displaySpeakerDialogue("Fates", strongFaithTaunts[idx]);
    } else if (player.faith >= 40.0f) {
        int idx = rand() % mediumFaithTaunts.size();
        displaySpeakerDialogue("Fates", mediumFaithTaunts[idx]);
    } else {
        int idx = rand() % weakFaithTaunts.size();
        displaySpeakerDialogue("Fates", weakFaithTaunts[idx]);
    }
}

// Function to ask faith-related questions and impact the player's faith level
void askFaithQuestions(Character& player) {
    srand(time(0)); // Random seed

    vector<pair<string, int>> questions = {
        {"Who was cursed to push a boulder uphill for eternity?\n1. Sisyphus\n2. Tantalus\n3. Icarus\n", 1},
        {"Which god was born fully armored from Zeus' head?\n1. Artemis\n2. Athena\n3. Apollo\n", 2},
        {"Who is the goddess of witchcraft and crossroads?\n1. Hera\n2. Hecate\n3. Demeter\n", 2},
        {"Who ferries souls across the river Styx?\n1. Hermes\n2. Charon\n3. Thanatos\n", 2}
    };

    // Ask 2 random faith-doubt questions
    for (int i = 0; i < 2; ++i) {
        int index = rand() % questions.size();
        auto question = questions[index];
        questions.erase(questions.begin() + index); // Remove it so it can't repeat
    
        int answer;
        bool valid = false;
    
        while (!valid) {
            displaySpeakerDialogue("Fates", question.first);
            cout << "Enter your answer (1, 2, or 3): ";
    
            cin >> answer;
    
            if (cin.fail() || answer < 1 || answer > 3) {
                cin.clear(); // clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
                displaySpeakerDialogue("Fates", "Tsk. We said *1, 2, or 3*, songbird.");
            } else {
                valid = true;
            }
        }
    
        if (answer == question.second) {
            displaySpeakerDialogue("Fates", "Maybe you know a thing or two...");
            player.faith += 5;
            if (player.faith > 100.0f) player.faith = 100.0f;
        } else {
            displaySpeakerDialogue("Fates", "Didn't think so. Little songbird lost.");
            player.faith -= 10;
            if (player.faith < 0.0f) player.faith = 0.0f;
        }
    }
    
}
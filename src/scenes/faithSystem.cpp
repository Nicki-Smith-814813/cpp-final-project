#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
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
struct MythQuestion {
    string question;
    vector<string> options;
    int correctIndex;
};

void mythQuestions(Character& player) {
    srand(time(0)); // Seed random

    printAsciiArt("fates.txt");

    vector<MythQuestion> questions = {
        {"Who was the hero that completed the Twelve Labors?", {"Perseus", "Heracles", "Theseus"}, 1},
        {"Who turned into a spider after being defeated by Athena?", {"Medusa", "Arachne", "Hera"}, 1},
        {"Who was cursed to turn everything they touched into gold?", {"Midas", "King Minos", "Persephone"}, 0},
        {"Who ferries souls across the River Styx?", {"Charon", "Hades", "Hermes"}, 0},
        {"Which goddess is associated with the hearth and home?", {"Athena", "Artemis", "Hestia"}, 2},
        {"Who is the goddess of love and beauty?", {"Aphrodite", "Hera", "Demeter"}, 0},
        {"Who flew too close to the sun?", {"Daedalus", "Icarus", "Perseus"}, 1},
        {"Who opened Pandora’s Box?", {"Hera", "Athena", "Pandora"}, 2},
        {"Who is the Greek god of war?", {"Apollo", "Ares", "Hephaestus"}, 1},
        {"Who is the ruler of the Underworld?", {"Poseidon", "Zeus", "Hades"}, 2},
        {"Which god is known for his winged sandals?", {"Hermes", "Dionysus", "Ares"}, 0},
        {"Who is the goddess of wisdom?", {"Hera", "Athena", "Hestia"}, 1},
        {"Who tamed Pegasus?", {"Perseus", "Bellerophon", "Achilles"}, 1},
        {"Who killed the Minotaur?", {"Theseus", "Heracles", "Jason"}, 0},
        {"Who stole fire from the gods?", {"Prometheus", "Epimetheus", "Hermes"}, 0},
        {"Who is the goddess of the hunt?", {"Artemis", "Athena", "Demeter"}, 0},
        {"Who judged the beauty contest between Hera, Athena, and Aphrodite?", {"Paris", "Achilles", "Odysseus"}, 0},
        {"Who was punished by having to roll a boulder uphill forever?", {"Tantalus", "Sisyphus", "Orpheus"}, 1},
        {"Who led the Argonauts?", {"Odysseus", "Theseus", "Jason"}, 2},
        {"Who is the Greek goddess of agriculture?", {"Hera", "Demeter", "Persephone"}, 1}
    };

    random_shuffle(questions.begin(), questions.end());

    int correctAnswers = 0;

    for (int i = 0; i < 5; ++i) {
        MythQuestion& q = questions[i];

        // Shuffle options
        vector<pair<int, string>> shuffled;
        for (int j = 0; j < 3; ++j) {
            shuffled.push_back({j, q.options[j]});
        }
        random_shuffle(shuffled.begin(), shuffled.end());

        cout << "\n" << q.question << "\n";
        for (int k = 0; k < shuffled.size(); ++k) {
            cout << (k + 1) << ". " << shuffled[k].second << "\n";
        }

        int answer;
        cout << "Enter your answer (1, 2, or 3): ";
        cin >> answer;

        int selectedIndex = shuffled[answer - 1].first;
        if (selectedIndex == q.correctIndex) {
            displaySpeakerDialogue("Fates", "Correct.");
            correctAnswers++;
            player.faith += 10;
        } else {
            displaySpeakerDialogue("Fates", "Wrong.");
            player.faith -= 10;
        }

        player.faith = max(0, min(100, player.faith));
    }

    // Final response
    if (correctAnswers == 5) {
        printAsciiArt("threads_glow.txt");
        displaySpeakerDialogue("Fates", "'Hmph... Impressive. Even we didn't expect such clarity from a mortal mind.'");
        displayDialogue("Their threads shimmer like constellations. Perhaps... fate bends.");
    } else if (correctAnswers >= 3) {
        displaySpeakerDialogue("Fates", "'You've done... acceptably.'");
        displayDialogue("They nod with cold amusement. 'The thread trembles, but does not yet snap.'");
    } else if (correctAnswers == 2) {
        dramaticPause(800);
        displayDialogue("\033[38;2;50;50;150mThe air grows heavy.\033[0m");
        displaySpeakerDialogue("Fates", "'Tch. That barely scratches the surface of truth.'");
        displayDialogue("They twist their thread tighter. 'We wonder... why you still try.'");
    } else {
        printAsciiArt("fates_snarl.txt");
        dramaticPause(1000);
        displayDialogue("\033[38;2;30;30;100mA chill grips your spine.\033[0m");
        displaySpeakerDialogue("Fates", "'Pitiful.'");
        displayDialogue("Their thread coils like a noose. 'You know nothing of fate, songbird.'");
        displayDialogue("They laugh — shrill and final.");
    }

    cout << "Your current faith level: " << player.faith << "%\n";
}

    

// Function to simulate the hades says challenge
bool hadesSaysChallenge(Character& player) {
    srand(time(0));

    vector<string> rawCommands = {
        "Stomp", "Bow", "Raise your hands", "Spin", "Touch your toes"
    };

    vector<string> expectedResponses;

    displaySpeakerDialogue("Hades", "Let's see if you can remember, mortal.");
    displayDialogue("He begins issuing commands, one after another...\n");

    for (int i = 0; i < 5; ++i) {
        int cmdIndex = rand() % rawCommands.size();
        bool isTrap = rand() % 2 == 0;

        string command = rawCommands[cmdIndex];

        if (isTrap) {
            displayDialogue(command);
            expectedResponses.push_back(""); // player should stay silent
        } else {
            displayDialogue("Hades says: " + command);
            expectedResponses.push_back(command); // player must match
        }
    }

    displayDialogue("\nNow, repeat the commands exactly, one at a time.");
    displayDialogue("(Type your responses exactly: example -> Bow)\n");

    int score = 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer

    for (int i = 0; i < 5; ++i) {
        cout << "Command #" << (i + 1) << ": ";
        string response;
        getline(cin, response);

        if (response == expectedResponses[i]) {
            ++score;
        }
    }

    displayDialogue("\nYou got " + to_string(score) + " out of 5 correct.\n");

    // Adjust stats based on performance
    if (score == 5) {
        displaySpeakerDialogue("Hades", "Impressive. Maybe there's hope for you yet.");
        player.faith += 10;
        player.trust += 10;
    } else if (score >= 3) {
        displaySpeakerDialogue("Hades", "You’re not entirely hopeless.");
        player.faith += 5;
        player.trust += 5;
    } else {
        displaySpeakerDialogue("Hades", "Pathetic. Try harder next time.");
        player.faith -= 5;
        player.trust -= 5;
    }

    // Clamp values between 0 and 100
    player.faith = max(0, min(100, player.faith));
    player.trust = max(0, min(100, player.trust));

    return (score >= 3); // return true if pass, false if fail
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
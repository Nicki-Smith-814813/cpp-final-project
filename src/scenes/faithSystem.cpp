#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <sstream>
#include <cmath>  // for abs()
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

    printAsciiArt("fates.txt");
    randomizedFatesTaunt(player); 

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
        for (size_t k = 0; k < shuffled.size(); ++k) {
            cout << (k + 1) << ". " << shuffled[k].second << "\n";
        }
        
        int answer;
        answer = getValidatedInput<int>("Enter your answer (1-3): ", 1, 3);
        int selectedIndex = shuffled[answer - 1].first;
        
        if (selectedIndex == q.correctIndex) {
            displaySpeakerDialogue("Fates", "*A rare spark. Don’t lose it.*");
            player.faith += 5;
            if (rand() % 2 == 0) randomizedFatesTaunt(player);  // optional extra taunt
            correctAnswers++;
        } else {
            displaySpeakerDialogue("Fates", "*Wrong again. Your thread weakens.*");
            player.faith -= 5;
            randomizedFatesTaunt(player);
        }
        

        player.faith = max(0, min(100, player.faith));
    }

    // Final response
    if (correctAnswers == 5) {
        printAsciiArt("threads_glow.txt");
        displaySpeakerDialogue("Fates", "Fates:'Hmph... Impressive. Even we didn't expect such clarity from a mortal mind.'");
        displayDialogue("Their threads shimmer like constellations. Perhaps... fate bends.");
    } else if (correctAnswers >= 3) {
        displaySpeakerDialogue("Fates", "Fates:'You've done... acceptably.'");
        displayDialogue("They nod with cold amusement.");
        displaySpeakerDialogue("Fates","Fates:'The thread trembles, but does not yet snap.'");
    } else if (correctAnswers == 2) {
        dramaticPause(800);
        displayDialogue("\033[38;2;50;50;150mThe air grows heavy.\033[0m");
        displaySpeakerDialogue("Fates", "Fates:'Tch. That barely scratches the surface of truth.'");
        displayDialogue("They twist their thread tighter.");
        displaySpeakerDialogue("Fates","Fates:'We wonder... why you still try.'");
    } else {
        printAsciiArt("fates_snarl.txt");
        dramaticPause(1000);
        displayDialogue("\033[38;2;30;30;100mA chill grips your spine.\033[0m");
        displaySpeakerDialogue("Fates", "Fates:'Pitiful.'");
        displayDialogue("Their thread coils like a noose.");
        displaySpeakerDialogue("Fates","Fates:'You know nothing of fate, songbird.'");
        displayDialogue("They laugh — shrill and final.");
    }

    cout << "Your current faith level: " << player.faith << "%\n";
}

    

// Function to simulate the hades says challenge
bool hadesSaysChallenge(Character& player) {

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
    randomizedFatesTaunt(player);
    displayDialogue("\nNow, repeat the commands exactly, one at a time.\n");
    displayDialogue("(If no 'Hades says:' before, simply hit enter to skip to the next command.)\n");
    displayDialogue("(Type your responses exactly: example -> Bow)\n");

    int score = 0;

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

    cout << "Your current faith level: " << player.faith << "%";
}


//Musical challenge
bool musicalGame(Character& player, bool isRetry, int difficultyLevel) {
    if (isRetry) {
        displaySpeakerDialogue("Hades", "You dare try again, boy? The melody grows longer...");
    } else {
        displaySpeakerDialogue("Hades", "Let's see if you can truly sing your way out of this place.");
    }

    int flashDelay = 600;
    int eraseDelay = 300;
    int startDelay = 1000;

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

    string notes[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Ti"};
    int numNotes = 7;
    vector<int> melody;

    displayDialogue("Hades leans back, watching Orpheus with an iron gaze...");
    randomizedFatesTaunt(player);
    displaySpeakerDialogue("Hades", "Here’s the melody. Listen carefully.\n");
    dramaticPause(startDelay);

    // Generate random melody
    for (int i = 0; i < melodyLength; ++i) {
        int noteIndex = rand() % numNotes;
        melody.push_back(noteIndex + 1);
    }

    auto playMelody = [&]() {
        for (int i = 0; i < melodyLength; ++i) {
            int noteIndex = melody[i] - 1;
            cout << notes[noteIndex] << " " << flush;
            dramaticPause(flashDelay);
            cout << "\r      \r" << flush;
            dramaticPause(eraseDelay);
        }
        cout << "\n\n";
    };

    // First playback
    playMelody();

    int replay = getValidatedInput<int>("Do you want to hear the melody again? (1 = Yes, 2 = No): ", 1, 2);
    if (replay == 1) {
        displaySpeakerDialogue("Fates", "*Listen once more...*");
        dramaticPause(500);
        playMelody();
        randomizedFatesTaunt(player); // second taunt before input
    }

    // Player input
    cout << "Enter the melody using numbers (1=Do,2=Re,3=Mi,4=Fa,5=So,6=La,7=Ti), separated by spaces:\n> ";
    string inputLine;
    getline(cin >> ws, inputLine);

    istringstream iss(inputLine);
    vector<int> playerSequence;
    int n;

    while (iss >> n) {
        if (n >= 1 && n <= 7) {
            playerSequence.push_back(n);
        } else {
            displaySpeakerDialogue("Fates", "*You played a forbidden note...*");
            player.faith -= 5;
            player.trust -= 3;
            if (player.faith < 0) player.faith = 0;
            if (player.trust < 0) player.trust = 0;
            return false;
        }
    }

    // Validate input length
    if (playerSequence.size() != melodyLength) {
        displaySpeakerDialogue("Fates", "*The sequence is the wrong length. Are you guessing?*");
        player.faith -= 5;
        player.trust -= 3;
        if (player.faith < 0) player.faith = 0;
        if (player.trust < 0) player.trust = 0;
        return false;
    }

    // Score accuracy
    int correct = 0;
    for (int i = 0; i < melodyLength; ++i) {
        if (playerSequence[i] == melody[i]) {
            correct++;
        }
    }

    int mistakes = melodyLength - correct;

    // Stat application and outcome
    if (mistakes == 0) {
        displaySpeakerDialogue("Hades", "Impressive. Your memory serves you well.");
        player.faith += 10;
        player.trust += 10;
        if (player.faith > 100) player.faith = 100;
        if (player.trust > 100) player.trust = 100;
        return true;
    } else if (mistakes <= 2) {
        displaySpeakerDialogue("Fates", "*Close enough... the thread trembles but does not break.*");
        player.faith += 5;
        player.trust += 5;
        if (player.faith > 100) player.faith = 100;
        if (player.trust > 100) player.trust = 100;
        return true;
    } else {
        displaySpeakerDialogue("Fates", "*You falter... the thread snaps.*");
        player.faith -= 10;
        player.trust -= 5;
        if (player.faith < 0) player.faith = 0;
        if (player.trust < 0) player.trust = 0;
        return false;
    }
        cout << "Your current faith level: " << player.faith << "%";}


// --------------------------------
// Randomized Fate Taunt Function
// --------------------------------
void randomizedFatesTaunt(const Character& player) 
{
    vector<string> strongFaithTaunts = {
        "*Strong thread yet, little songbird... but can you hold it?*",
        "*A golden thread, spun tight... but even gold can snap.*",
        "*You shine still... will you survive the loom?*",
        "*So sure of your steps... pride makes a beautiful noose.*",
        "*Confidence suits you... until it doesn't.*",
        "*Your faith burns bright — don’t let it blind you.*",
        "*Even stars fall, boy. Will you?*",
        "*You walk the thread like a tightrope. One gust...*",
        "*Bold. Brash. Bound to fall harder.*",
        "*You think you’re winning? The Fates are always ahead.*"
    };
    

    vector<string> mediumFaithTaunts = {
        "*The thread frays... one wrong note and you're gone.*",
        "*Your fate hangs by a thread, boy.*",
        "*The loom trembles. Your song grows thin.*",
        "*So close... and yet the end still yawns before you.*",
        "*You waver, songbird. The wind picks up.*",
        "*Hope? Hope doesn't mend broken threads.*",
        "*Almost strong. Almost brave. Almost enough.*",
        "*The cracks show. We see them all.*",
        "*Balanced between ruin and resolve.*",
        "*Half a step from greatness... or the grave.*"
    };
    

    vector<string> weakFaithTaunts = {
        "*Ha! Barely a thread left! One pull and you fall apart.*",
        "*A breath could scatter you to dust.*",
        "*The song is almost over. One wrong note, and you're lost forever.*",
        "*We’ve seen stronger men crumble for less.*",
        "*Is this all the faith you’ve got left? Pathetic.*",
        "*Orpheus, even shadows pity you now.*",
        "*You should have stayed above.*",
        "*Why struggle? You're already unraveling.*",
        "*Torn. Tired. Tempted. It shows.*",
        "*We could cut the thread now and save us the boredom.*"
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
    std::vector<MCQuestion> questions = {
        {"Who is the god of wine, theatre, and revelry?", {"Hephaestus", "Apollo", "Dionysus"}, 2},
        {"What creature had the head of a lion, a goat’s body, and a serpent’s tail?", {"Chimera", "Cerberus", "Hydra"}, 0},
        {"Which mortal was allowed to live forever but continued aging?", {"Tithonus", "Orpheus", "Phaethon"}, 0},
        {"Which Greek hero killed the Gorgon Medusa?", {"Theseus", "Perseus", "Heracles"}, 1},
        {"Who drove the sun chariot across the sky?", {"Apollo", "Helios", "Zeus"}, 1},
        {"What monstrous dog guarded the entrance to the Underworld?", {"Cerberus", "Orthrus", "Hydra"}, 0},
        {"Which Titan was condemned to hold up the sky for eternity?", {"Atlas", "Cronus", "Hyperion"}, 0},
        {"Which goddess emerged fully grown from Zeus’s head?", {"Artemis", "Athena", "Hera"}, 1},
        {"Which king's hubris led him to feast on the gods and be cursed?", {"Sisyphus", "Tantalus", "Oedipus"}, 1},
        {"What winged horse was born from Medusa’s blood?", {"Pegasus", "Griffin", "Hippogriff"}, 0},
        {"Which mortal woman was the mother of Achilles?", {"Andromache", "Thetis", "Leda"}, 1},
        {"Which goddess cursed Echo to only repeat the words of others?", {"Aphrodite", "Hera", "Demeter"}, 1},
        {"What is the name of the labyrinth's architect?", {"Icarus", "Minos", "Daedalus"}, 2},
        {"Who was turned into a laurel tree to escape Apollo?", {"Daphne", "Calliope", "Andromeda"}, 0},
        {"Which Titan ruled during the Golden Age?", {"Cronus", "Prometheus", "Oceanus"}, 0},
        {"Which hero solved the riddle of the Sphinx?", {"Odysseus", "Oedipus", "Jason"}, 1},
        {"What sea monster did Perseus save Andromeda from?", {"Scylla", "Cetus", "Charybdis"}, 1},
        {"Who was the mother of the Minotaur?", {"Pasiphaë", "Ariadne", "Phaedra"}, 0},
        {"What river in the Underworld caused forgetfulness?", {"Lethe", "Styx", "Acheron"}, 0},
        {"Which goddess transformed Actaeon into a stag?", {"Artemis", "Hera", "Athena"}, 0}
    };

    // Ask 5 random questions
    for (int i = 0; i < 5 && !questions.empty(); ++i) {
        int index = rand() % questions.size();
        MCQuestion q = questions[index];
        questions.erase(questions.begin() + index);

        randomizedFatesTaunt(player);
        displaySpeakerDialogue("Fates", q.questionText);
        for (int j = 0; j < 3; ++j) {
            std::cout << j + 1 << ". " << q.options[j] << std::endl;
        }

        int answer = getValidatedInput<int>("Enter your answer (1-3): ", 1, 3);
        if (answer - 1 == q.correctIndex) {
            displaySpeakerDialogue("Fates", "Maybe you know a thing or two...");
            player.faith += 5;
        } else {
            displaySpeakerDialogue("Fates", "Didn't think so. Little songbird lost.");
            player.faith -= 5;
        }

        // Clamp faith between 0 and 100
        if (player.faith > 100.0f) player.faith = 100.0f;
        if (player.faith < 0.0f) player.faith = 0.0f;
    }
    cout << "Your current faith level: " << player.faith << "%";
}


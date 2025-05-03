#ifndef FAITHSYSTEM_H
#define FAITHSYSTEM_H
#include "characters.h"
#include <vector>
#include <string>
extern float faith;

// Functions to manage the player's faith
void increaseFaith(Character& player, float amount);
void decreaseFaith(Character& player, float amount);

// Mythology quiz function
struct MythQuestion {
    std::string question;
    std::vector<std::string> options;
    int correctIndex;
};

void mythQuestions(Character& player);

//Memory challenge
bool hadesSaysChallenge(Character& player);

//The lyre song scene game
bool musicalGame(Character& player, bool isRetry = false, int difficultyLevel = 1);
void randomizedFatesTaunt(const Character& player);

//Doubt comes in with tricky fingers.
void askFaithQuestions(Character& player);

struct MCQuestion {
    std::string questionText;
    std::vector<std::string> options;
    int correctIndex;
};


#endif

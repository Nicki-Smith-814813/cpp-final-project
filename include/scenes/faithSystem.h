#ifndef FAITHSYSTEM_H
#define FAITHSYSTEM_H
#include "characters.h"
extern float faith;

// Functions to manage the player's faith
void increaseFaith(Character& player, float amount);
void decreaseFaith(Character& player, float amount);

// Mythology quiz function
void mythQuestions(Character& player);

//Memory challenge
bool hadesSaysChallenge();

//The lyre song scene game
bool musicalGame();

//Doubt comes in with tricky fingers.
void askFaithQuestions(Character& player);

#endif

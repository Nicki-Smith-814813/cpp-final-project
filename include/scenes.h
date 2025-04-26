// scenes.h
#ifndef SCENES_H
#define SCENES_H

#include "characters.h"

void hermesNarration();
void persephoneAndHadesConflict();
void talkToEurydice(Character& player);
void chantI();
void WaitforMe();
void howlong();
void chantII();
void epicIII();
void doubtcomesin();
void roadtohell();

// Foraging simulator function
void forageForResources();
#endif // SCENES_H

// Faith variable (this could also be declared in the game state)
extern int faith;  // Or you could track this in the player struct

// Myth question function
void mythQuestions();



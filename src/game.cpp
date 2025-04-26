// game.cpp
#include <iostream>
#include "game.h"
#include "characters.h"
#include "scenes.h"

Game::Game() {
    // Initialize the game here
    init();
}

void Game::init() {
    player.name = "Orpheus";
    player.faith = 10;
    player.trust = 10;
}

void Game::start() {
    std::cout << "Welcome to Hadestown RPG!\n";
    playIntro();
}

void Game::playIntro() {
    hermesNarration();
    persephoneAndHadesConflict();
    talkToEurydice(player);
}

void Game::chantI() {

}

void Game::waitforme() {

}
void Game::howlong() {

}
void Game::chantII() {

}
void Game::epicIII() {

}
void Game::doubtcomesin() {

}
void Game::roadtohell() {

}

void Game::endGame() {
    std::cout << "Thanks for playing! See you next time.\n";
}

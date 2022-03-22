#pragma once

#include "dice.h"

#define NDICE 10
#define NSIDES 6

class Game{
public:
    Game();
    ~Game();

public:
    void play();

protected:
    void rollLocked(Dice &dice, bool *dielocks);
    void updateLocks(Dice &dice, bool *dielocks, int lockNumber);
    void printDice(Dice &dice, bool *dielocks);
    int chooseCompNumber(Dice &dice);
    bool hasWinner(bool *dielocks);

};

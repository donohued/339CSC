#pragma once

#include "dice.h"

#define NDICE 10
#define NSIDES 6

class Tenzi
{
public:
	Tenzi();
	~Tenzi();

public:
	void play();

protected:
	bool isWinner(bool* dieLocks);
	void roll(Dice &dice, bool* dieLocks);
	void updateLocks(Dice &dice, bool *dieLocks, int lockNumber);
	void printDice(Dice &dice, bool *dieLocks);
	int chooseComputerNumber(Dice &dice);
};
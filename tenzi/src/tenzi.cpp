#include <iostream>

#include "tenzi.h"

Tenzi::Tenzi()
{

}

Tenzi::~Tenzi()
{

}

void Tenzi::play()
{
	std::string playerName;

	Dice playerDice(NDICE, NSIDES);
	int playerNumber = 0;
	bool playerDiceLocks[NDICE] = { false };

	Dice computerDice(NDICE, NSIDES);
	int computerNumber = 0;
	bool computerDiceLocks[NDICE] = { false };

	std::cout << "Welcome to Tenzi! Please enter your name: ";
	std::cin >> playerName;

	std::cout << "Hello, " << playerName << ". Here is your first roll:" << std::endl;

	playerDice.roll();
	this->printDice(playerDice, playerDiceLocks);

	std::cout << "What die value would you like to roll for? ";
	std::cin >> playerNumber;

	this->updateLocks(playerDice, playerDiceLocks, playerNumber);

	this->printDice(playerDice, playerDiceLocks);

	std::cout << std::endl;
	std::cout << "The computer rolls:" << std::endl;

	computerDice.roll();
	this->printDice(computerDice, computerDiceLocks);

	computerNumber = this->chooseComputerNumber(computerDice);

	this->updateLocks(computerDice, computerDiceLocks, computerNumber);

	std::cout << "The computer will roll for " << computerNumber << "s." << std::endl;

	this->printDice(computerDice, computerDiceLocks);

	bool gameOver = false;
	while (gameOver == false) {
		std::string rollString;

		std::cout << std::endl;
		std::cout << "Enter R to roll:";
		std::cin >> rollString;

		this->roll(playerDice, playerDiceLocks);
		this->updateLocks(playerDice, playerDiceLocks, playerNumber);
		std::cout << playerName << " rolls:" << std::endl;
		this->printDice(playerDice, playerDiceLocks);

		if (this->isWinner(playerDiceLocks)) {
			std::cout << playerName << " WINS!!!" << std::endl;
			gameOver = true;
			continue;
		}

		this->roll(computerDice, computerDiceLocks);
		this->updateLocks(computerDice, computerDiceLocks, computerNumber);
		std::cout << "COMPUTER rolls:" << std::endl;
		this->printDice(computerDice, computerDiceLocks);

		if (this->isWinner(computerDiceLocks)) {
			std::cout << "COMPUTER WINS!!!" << std::endl;
			gameOver = true;
			continue;
		}
	}
}

bool Tenzi::isWinner(bool *dieLocks)
{
	for (int x = 0; x < NDICE; x++) {
		if (dieLocks[x] == false) {
			return false;
		}
	}

	return true;
}

void Tenzi::roll(Dice &dice, bool *dieLocks)
{
	for (int x = 0; x < NDICE; x++) {
		if (dieLocks[x] == false) {
			dice.rollDie(x);
		}
	}
}

void Tenzi::updateLocks(Dice& dice, bool* dieLocks, int lockNumber)
{
	for (int x = 0; x < NDICE; x++) {
		if (dice.dieValue(x) == lockNumber) {
			dieLocks[x] = true;
		}
	}
}

void Tenzi::printDice(Dice& dice, bool* dieLocks)
{
	for (int x = 0; x < NDICE; x++) {
		std::cout << dice.dieValue(x);
		if (dieLocks[x] == true) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int Tenzi::chooseComputerNumber(Dice& dice)
{
	int values[NSIDES] = { 0 };

	for (int x = 0; x < NDICE; x++) {
		values[dice.dieValue(x) - 1]++;
	}

	int lockNumber = 0;
	int highCount = 0;

	for (int x = 0; x < NSIDES; x++) {
		if (values[x] > highCount) {
			lockNumber = x + 1;
			highCount = values[x];
		}
	}

	return lockNumber;
}
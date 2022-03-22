#include <iostream>

#include "game.h"

Game::Game(){

}

Game::~Game(){

}

void Game::play(){
    std::string playerName;
    std::string winner;

    Dice playerDice(NDICE, NSIDES);
    int playerNumber = 0;
    bool playerDiceLock[NDICE] = {false};
    
    Dice cpuDice(NDICE, NSIDES);
    int cpuNumber = 0;
    bool cpuDiceLock[NDICE] = {false};

    std::cout << "Welcome to the game of tenzi. ";
    std::cout << "Enter your name below:" << std::endl;

    std::cin >> playerName;
    std::cout << "Hello, " << playerName << "." << std::endl;
    std::cout << "Your dice rolls:" << std::endl;

    playerDice.roll();
    this->printDice(playerDice, playerDiceLock);
    std::cout << "Choose a number to lock-in." << std::endl;

    std::cin >> playerNumber;
    this->updateLocks(playerDice, playerDiceLock, playerNumber);
    this->printDice(playerDice, playerDiceLock);

    std::cout << "You chose to lock-in the number: " << playerNumber << std::endl;
    std::cout << "Computer roll:" << std::endl;

    cpuDice.roll();

    this->printDice(cpuDice, cpuDiceLock);
    cpuNumber = this->chooseCompNumber(cpuDice);

    std::cout << "Computer decided to lock-in number: " << cpuNumber << std::endl;

    this->updateLocks(cpuDice, cpuDiceLock, cpuNumber);
    this->printDice(cpuDice, cpuDiceLock);

    fflush(stdout);
    bool gameover = false;
    //GAME LOOP
    while(!gameover){
        std::string str;

        std::cout << "Press enter to roll again..." << std::endl;
        std::cin >> str;

        std::cout << "Your new roll and locked numbers:" << std::endl;
        rollLocked(playerDice, playerDiceLock);
        this->updateLocks(playerDice, playerDiceLock, playerNumber);
        this->printDice(playerDice, playerDiceLock);

        if(this->hasWinner(playerDiceLock)){
            winner = playerName;
            gameover = true;
            continue;
        }

        std::cin >> str;

        std::cout << "Computers new roll and locked numbers:" << std::endl;
        rollLocked(cpuDice, cpuDiceLock);
        this->updateLocks(cpuDice, cpuDiceLock, cpuNumber);
        this->printDice(cpuDice, cpuDiceLock);

        if(this->hasWinner(playerDiceLock)){
            winner = "COMPUTER";
            gameover = true;
            continue;
        }

    }


    std::cout << "The winner of the game is: " << winner << std::endl;
    std::cout << "Bye bye!" << std::endl;
    

}

void Game::rollLocked(Dice &dice, bool *dielocks){
    for (int i = 0; i < NDICE; i++){
        if(!dielocks[i])
            dice.rollDie(i);
    }
    
}

void Game::updateLocks(Dice &dice, bool *dielocks, int lockNumber){
    for (int i = 0; i < NDICE; i++){
        if(dice.dieValue(i) == lockNumber){
            dielocks[i] = true;
        }
    }
}

void Game::printDice(Dice &dice, bool *dielocks){
    for(int i = 0; i < NDICE; i++){
        std::cout << dice.dieValue(i);
        if (dielocks[i]){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int Game::chooseCompNumber(Dice &dice){
    for (int i = 0; i < NDICE; i++){
        //better choosing method
    }
    return dice.dieValue(0);   
}

bool Game::hasWinner(bool *dielocks){
    for (int i = 0; i < NDICE; i++){
        if(!dielocks[i]){
            return false;
        }
    }
    
    return true;
}
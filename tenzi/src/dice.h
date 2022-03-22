#pragma once

#include <vector>

#include "die.h"

class Dice 
{
public:
    Dice(int ndice, int nsides);
    Dice(const Dice& copy);
    ~Dice();

public:
    void roll();
    int rollDie(int die);
    int dieValue(int die);
    int rollValue();

protected:
    std::vector<Die*> dice;
};
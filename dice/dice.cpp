#include "dice.h"

Dice::Dice(int ndice, int nsides)
{
    for (int x = 0; x < ndice; x++) {
        Die die(nsides);
        this->dice.push_back(die);
    }
}

Dice::~Dice()
{

}

void Dice::roll()
{
    for (int x = 0; x < this->dice.size(); x++) {
        this->dice[x].roll();
    }
}

int Dice::dieValue(int die)
{
    if (die < 0 || die > this->dice.size() - 1) {
        return 0;
    }

    return this->dice[die].getLastRoll();
}

int Dice::rollValue()
{
    int value = 0;

    for (int x = 0; x < this->dice.size(); x++) {
        value += this->dice[x].getLastRoll();
    }

    return value;
}
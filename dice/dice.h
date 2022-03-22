#include <vector>

#include "die.h"

class Dice 
{
public:
    Dice(int ndice, int nsides);
    ~Dice();

public:
    void roll();
    int dieValue(int die);
    int rollValue();

protected:
    std::vector<Die> dice;
};
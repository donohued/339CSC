#include <stdlib.h>

#include "die.h"

Die::Die(int nsides)
{
    this->nsides = nsides;
    this->lastRoll = 0;
}

Die::Die(const Die& copy)
{
    this->nsides = copy.nsides;
    this->lastRoll = copy.lastRoll;
}

Die::~Die()
{

}

int Die::roll()
{
    this->lastRoll = rand() % this->nsides + 1;

    return this->getLastRoll();
}

int Die::getLastRoll()
{
    return this->lastRoll;
}
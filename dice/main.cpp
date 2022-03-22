#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "dice.h"


int main(int argc, char **argv)
{
    srand(time(NULL));

    Dice dice1(10, 6);
    Dice dice2(10, 6);

    dice1.roll();
    dice2.roll();

    std::cout << "Roll #1" << std::endl;
    for (int x = 0; x < 10; x++) {
        std::cout << "Die #" << (x + 1) << " roll is " << dice1.dieValue(x) << std::endl;
    }
    std::cout << std::endl << "Roll total is " << dice1.rollValue() << std::endl;

    std::cout << std::endl;

    std::cout << "Roll #2" << std::endl;
    for (int x = 0; x < 10; x++)
    {
        std::cout << "Die #" << (x + 1) << " roll is " << dice2.dieValue(x) << std::endl;
    }
    std::cout << std::endl << "Roll total is " << dice2.rollValue() << std::endl;

    std::cout << std::endl;

    if (dice1.rollValue() == dice2.rollValue()) {
        std::cout << "A TIE!!!" << std::endl;
    } else if (dice1.rollValue() > dice2.rollValue()) {
        std::cout << "Roll #1 WINS!" << std::endl;
    } else {
        std::cout << "Roll #2 WINS!" << std::endl;
    }

    return 0;
}
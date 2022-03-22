#include <iostream>
#include <time.h>

#include "deck.h"

int main(int argc, char **argv)
{

    srand(time(NULL));

    Deck deck;

    std::cout << "Shuffling the deck and drawing 10 cards:" << std::endl;

    deck.shuffle();

    for (int i = 0; i < 10; i++){
        deck.draw()->print();
    }


    std::cout << "\nShuffling the deck again and drawing 10 cards:" << std::endl;

    deck.shuffle();

    for (int i = 0; i < 10; i++){
        deck.draw()->print();
    }

    return 1;
}

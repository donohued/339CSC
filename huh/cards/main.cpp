#include <iostream>
#include <stdlib.h>
#include "card.h"

using std::string;

void printCard(Card c1){
    const char *suits[4] = {"Hearts", "Spades", "Clubs", "Diamonds"};
    string value = "";
    switch (c1.get_value())
    {
    case 11:
        value = "Jack";
        break;
    case 12:
        value = "King";
        break;
    case 13:
        value = "Queen";
        break;
    case 14:
        value = "Ace";
        break;
    default:
        value = std::to_string(c1.get_value());
        break;
    }

    std::cout << value << " of " << suits[c1.get_suit()] << std::endl;
}

void printValComp(Card c1, Card c2){
    int ccomp = c1.cmp_value(c2);

    if(ccomp > 0)
        std::cout << "The first card is greater than the second card." << std::endl;
    else if(ccomp < 0)
        std::cout << "The first card is less than the second card." << std::endl;
    else
        std::cout << "The two cards have the same value." << std::endl;
}

void printSuitComp(Card c1, Card c2){
    if(c1.cmp_suit(c2) == 0)
        std::cout << "The two cards do NOT share the same suit." << std::endl;
    else
        std::cout << "The two cards DO share the same suit." << std::endl;
}

int main(int argc, char **argv){
    const char *values[] = {"2", "3", "4"};
    //TODO: Generate 5 cards
    Card cardOne(3, heart);
    Card cardTwo(9, heart);
    Card cardThree(14, spade);
    Card cardFour(3, diamond);
    Card cardFive(14, club);

    printCard(cardOne);
    printCard(cardThree);

    printSuitComp(cardOne, cardFive);
    printSuitComp(cardTwo, cardOne);

    printValComp(cardFour, cardThree);
    printValComp(cardFive, cardThree);
    




    return 0;
    //TODO: Print cards to stdout
    //TODO: Compare card suits to eachother
    //TODO: Compare card values to eachother

}




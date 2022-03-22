#include <stdlib.h>
#include "card.h"

Card::Card(int value, FACE suit){
    //this->value = (rand() % 12) +2;
    //this->suit = FACE(rand() % 4);
    this->value = value;
    this->suit = suit;
}

Card::~Card(){
    
}

int Card::get_value(){
    return this->value;
}

FACE Card::get_suit(){
    return this->suit;
}

int Card::cmp_value(Card cval){
    return value - cval.value;
}

bool Card::cmp_suit(Card cval){
    if (cval.suit == suit)
        return true;
    return false;
}

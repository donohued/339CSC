#include <iostream>
#include <stack>

#include "war.h"

//TODO: make deck size a const?

War::War(Deck &deck){
    deck.shuffle();

    Deal(deck);

}

War::~War(){

}

void War::Deal(Deck &deck){
    for (int i = Card::Suit::CLUB; i <= Card::Suit::SPADE / 2; i++)
    {
        for (int j = Card::Value::TWO; j <= Card::Value::ACE; j++)
        {
            std::cout << i << " " << j << std::endl;
            playerHand.push(deck.draw());
            std::cout << "Player got";
            this->playerHand.top()->print();

            computerHand.push(deck.draw());
            std::cout << "Comp got";
            this->computerHand.top()->print();
        }
        
        
    }
}
#include <iostream>
#include <random>
#include <stack>

#include "deck.h"

static std::random_device rd;
static std::mt19937 rng(rd());

Deck::Deck(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card *card = new Card((Card::Suit)i, (Card::Value)j);
            this->deck.push_back(card);
        }
    }
}

Deck::~Deck(){
    for (int i = 0; i < this->deck.size(); i++)
    {
        delete this->deck[i];
    }
}

Card* Deck::draw(){
    Card* top = this->shuffled.top();
    this->shuffled.pop();
    return top;
}

void Deck::shuffle(){

    while(this->shuffled.size() > 0){
        this->shuffled.pop();
    }

    std::shuffle(this->deck.begin(), this->deck.end(), rng);



}

void Deck::shuffleHelper(int splits){

    for (int i = 0; i < splits; i++)
    {
        std::stack<Card*> splitDeck;
        int cut = rand() % (this->deck.size() / 2) + 1;

        for (int j = 0; j < cut; j++)
        {
            splitDeck.push(this->deck.back());
            this->deck.pop_back();
        }

        int slip = rand() % (this->deck.size() / 2) + 1;
        for (int k = splitDeck.size(); k > 0; k--)
        {
            this->deck.insert(this->deck.begin() + slip, splitDeck.top());
            splitDeck.pop();
        }
        
    }
    
}
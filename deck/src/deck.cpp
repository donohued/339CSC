#include <iostream>
#include <stack>

#include "deck.h"

Deck::Deck(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card *card = new Card((Card::Suit)i, (Card::Value)j);
            this->deck.push_back(card);
        }
    }
}


Deck::Deck(const Deck& copy){
    for(int i = 0; i < copy.deck.size(); i++){
            Card *card = new Card(*(copy.deck[i]));
            this->deck.push_back(card);
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

    if(this->shuffled.size() < this->deck.size()){

        shuffleHelper(this->deck.size());

        while(!this->shuffled.empty()){
            this->shuffled.pop();
        }
    
        for(int i = 0; i < this->deck.size(); i++)
        {
          this->shuffled.push(this->deck[i]);
        }
    }

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
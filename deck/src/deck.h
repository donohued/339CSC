#include <vector>
#include <stack>

#include "card.h"

class Deck{
    public:
        Deck();
        Deck(const Deck& copy);
        ~Deck();

    public:
        void shuffle();
        void printDeck();
        Card* draw();
        

    protected:
        std::vector<Card*> deck;
        std::stack<Card*> shuffled;
        void shuffleHelper(int splits);
};
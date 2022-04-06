#include "deck.h"

class War{
    public:
        War(Deck &deck);
        ~War();
    public:
    protected:
        void Deal(Deck &deck);
        std::deque<Card*> playerDeck;
        std::deque<Card*> computerDeck;
    private:
        bool GameOver(int p, int c);
};
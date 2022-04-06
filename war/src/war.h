#include "deck.h"

class War{
    public:
        War(Deck &deck);
        ~War();
    public:
    protected:
        void Deal(Deck &deck);

        std::stack<Card*> playerHand;
        std::stack<Card*> computerHand;
    private:
};
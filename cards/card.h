#pragma once

enum FACE {heart, spade, club, diamond};

class Card{
    public:
        Card(int value, FACE suit);
        ~Card();

    public:
        int get_value();
        FACE get_suit();
        int cmp_value(Card);
        bool cmp_suit(Card);

    protected:
        int value;
        FACE suit;
};
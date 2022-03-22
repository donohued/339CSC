#pragma once

class Die{
    public:
        Die(int nsides);
        ~Die();

    public:
        int roll();

    protected:
        int nsides;
};
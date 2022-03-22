#pragma once

class Die
{
public:
    Die(int nsides);
    Die(const Die& copy);
    ~Die();

public:
    int roll();
    int getLastRoll();

protected:
    int nsides;
    int lastRoll;
};
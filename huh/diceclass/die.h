class Die
{
public:
    Die(int nsides);
    ~Die();

public:
    int roll();
    int getLastRoll();

protected:
    int nsides;
    int lastRoll;
};
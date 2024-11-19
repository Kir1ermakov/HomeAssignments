#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "transformer.h"

class Autobot : public Transformer
{
    public:
    Autobot(Gun* gun, const Heart& heart);

    uint getCountFriends();
    uint getHumanity();

    void setCountFriends(uint countFriends);
    void setHumanity(uint humanity);

    bool makeFriends();

    private:
    uint _humanity;
    uint _countFriends;
};

#endif // AUTOBOT_H
#include "autobot.h"

Autobot::Autobot(Gun* gun, const Heart& heart): Transformer(gun, heart), _countFriends(0), _humanity(10) {}

uint Autobot::getCountFriends()
{
    return _countFriends;
}

uint Autobot::getHumanity()
{
    return _humanity;
}

void Autobot::setCountFriends(uint countFriends)
{
    _countFriends = countFriends;
}

void Autobot::setHumanity(uint humanity)
{
    _humanity = humanity;
}

bool Autobot::makeFriends()
{
    _humanity++;
    _countFriends++;
    uint health = getHealth();
    setHealth(health + 10);
    return true;
}
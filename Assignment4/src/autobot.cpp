#include "autobot.h"
#include <iostream>

Autobot::Autobot(Gun* gun, const Heart& heart): Transformer(gun, heart), _countFriends(0), _humanity(10) {}

Autobot::Autobot(Gun* gun, const Heart& heart, uint countFriends, uint humanity): Transformer(gun, heart), _countFriends(countFriends), _humanity(humanity) {}

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

bool Autobot::operator>(const Autobot& other) const
{
    if (static_cast<const Transformer&>(*this) > static_cast<const Transformer&>(other)) return true;
    if (_countFriends > other._countFriends) return true;
    return _humanity > other._humanity;
}

bool Autobot::operator<(const Autobot& other) const
{
    return other > *this;
}

bool Autobot::operator==(const Autobot& other) const
{
    return (static_cast<const Transformer&>(*this) == static_cast<const Transformer&>(other)) &&
           (_countFriends == other._countFriends) && (_humanity == other._humanity);
}

std::ostream& operator<<(std::ostream& os, const Autobot& a)
{
    os << "About your Autobot:" << std::endl;
    os << static_cast<const Transformer&>(a);
    os << ", Count of Friends: " << a._countFriends;
    os << ", Humanity: " << a._humanity;
    return os;
}
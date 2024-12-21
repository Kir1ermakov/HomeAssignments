// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "transformer.h"

class Autobot : public Transformer
{
public:
    Autobot(Gun* gun, const Heart& heart);

    Autobot(Gun* gun, const Heart& heart, uint countFriends, uint humanity);

    uint getCountFriends();
    uint getHumanity();

    void setCountFriends(uint countFriends);
    void setHumanity(uint humanity);

    bool makeFriends();

    friend std::ostream& operator<<(std::ostream& os, const Autobot& a);

    bool operator>(const Autobot& other) const;
    bool operator<(const Autobot& other) const;
    bool operator==(const Autobot& other) const;

private:
    uint _countFriends;
    uint _humanity;

};

#endif // AUTOBOT_H
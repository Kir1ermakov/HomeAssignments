// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "transformer.h"

class Neutral : public Transformer
{
    public:
    Neutral(Gun* gun, const Heart& heart);

    uint getCountFriends();
    uint getHumanity();
    uint getCountEnemies();
    uint getAgression();

    void setCountFriends(uint countFriends);
    void setHumanity(uint humanity);
    void setCountEnemies(uint countEnemies);
    void setAgression(uint agression);

    bool makeFriends();
    bool makeEnemies();

    private:
    uint _humanity;
    uint _countFriends;
    uint _countEnemies;
    uint _agression;
};

#endif // NEUTRAL_H

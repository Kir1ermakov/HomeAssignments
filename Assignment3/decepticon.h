#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "transformer.h"

class Decepticon : public Transformer
{
    public:
    Decepticon(Gun* gun, const Heart& heart);

    uint getCountEnemies();
    uint getAgression();

    void setCountEnemies(uint countEnemies);
    void setAgression(uint agression);

    bool makeEnemies();

    private:
    uint _countEnemies;
    uint _agression;
};

#endif // DECEPTICON_H
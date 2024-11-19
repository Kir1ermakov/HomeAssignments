#include "decepticon.h"

Decepticon::Decepticon(Gun* gun, const Heart& heart) : Transformer(gun, heart), _countEnemies(0), _agression(10) {}

uint Decepticon::getCountEnemies()
{
    return _countEnemies;
}

uint Decepticon::getAgression()
{
    return _agression;
}

void Decepticon::setCountEnemies(uint countEnemies)
{
    _countEnemies = countEnemies;
}

void Decepticon::setAgression(uint agression)
{
    _agression = agression;
}

bool Decepticon::makeEnemies()
{
    _countEnemies++;
    _agression++;
    uint health = getHealth();
    setHealth(health - 5);
    uint damage = getDamage();
    setDamage(damage + 15);
    return true;
}

// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#include "decepticon.h"
#include <iostream>

Decepticon::Decepticon(Gun* gun, const Heart& heart) : Transformer(gun, heart), _countEnemies(0), _agression(10) {}

Decepticon::Decepticon(Gun* gun, const Heart& heart, uint countEnemies, uint agression) : Transformer(gun, heart), _countEnemies(countEnemies), _agression(agression) {}



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

bool Decepticon::operator>(const Decepticon& other) const
{
    if (static_cast<const Transformer&>(*this) > static_cast<const Transformer&>(other)) return true;
    if (_countEnemies > other._countEnemies) return true;
    return _agression > other._agression;
}

bool Decepticon::operator<(const Decepticon& other) const
{
    return other > *this;
}

bool Decepticon::operator==(const Decepticon& other) const
{
    return (static_cast<const Transformer&>(*this) == static_cast<const Transformer&>(other)) &&
           (_countEnemies == other._countEnemies) && (_agression == other._agression);
}

std::ostream& operator<<(std::ostream& os, const Decepticon& d)
{
    os << "Abot your Decepticon:" << std::endl;
    os << static_cast<const Transformer&>(d);
    os << ", Count of Enemies: " << d._countEnemies;
    os << ", Agression: " << d._agression;
    return os;
}
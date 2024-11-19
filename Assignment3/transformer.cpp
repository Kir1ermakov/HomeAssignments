#include "transformer.h"

Transformer::Transformer(Gun* gun, const Heart& heart)
    : _gun(gun), _heart(heart), _health(100), _energy(50), _damage(40), _luck(5) {}
Transformer::~Transformer()
{}
uint Transformer::getHealth()
{
    return _health;
}
uint Transformer::getEnergy()
{
    return _energy;
}
uint Transformer::getDamage()
{
    return _damage;
}
uint Transformer::getLuck()
{
    return _luck;
}

void Transformer::setHealth(uint health)
{
    _health = health;
}
void Transformer::setEnergy(uint energy)
{
    _energy = energy;
}
void Transformer::setDamage(uint damage)
{
    _damage = damage;
}
void Transformer::setLuck(uint luck)
{
    _luck = luck;
}

bool Transformer::shock()
{
    if (_energy > 0)
    {
        _energy--;
        return true;
    }
    
    return false;
}
bool Transformer::takeDamage()
{
    if (_health < 1)
    {
        return false;
    }

    _health--;
    return true;
}   
// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment5

#include "transformer.h"
#include <iostream>

Transformer::Transformer(Gun* gun, const Heart& heart): _health(100), _energy(50), _damage(40), _luck(5), _gun(gun), _heart(heart) {}

Transformer::Transformer(Gun* gun, const Heart& heart, uint health, uint energy, uint damage, uint luck): _health(health), _energy(energy), _damage(damage), _luck(luck), _gun(gun), _heart(heart) {}

void Transformer::transform() const
{
    std::cout << "Transformer: transform()\n";
}
void Transformer::openFire() const
{
    std::cout << "Transformer: openFire()\n";
}
void Transformer::ultra() const
{
    std::cout << "Transformer: ultra()\n";
}

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

bool Transformer::operator>(const Transformer& other) const
{

    if (_health > other._health) return true;
    if (_health < other._health) return false;
    if (_energy > other._energy) return true;
    if (_energy < other._energy) return false;
    return _damage > other._damage;
}

bool Transformer::operator<(const Transformer& other) const
{
    return other > *this;
}

bool Transformer::operator==(const Transformer& other) const
{
    return (_health == other._health && _energy == other._energy && _damage == other._damage);
}

std::ostream& operator<<(std::ostream& os, const Transformer& t)
{
    os << "Health: " << t._health << ", Power: " << t._energy << ", Damage: "
       << t._damage << ", Luck: " << t._luck;
    return os;
}


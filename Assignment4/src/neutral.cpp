// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#include "neutral.h"

Neutral::Neutral(Gun* gun, const Heart& heart)
    : Transformer(gun, heart), _countFriends(0), _countEnemies(0), _humanity(0), _agression(0) {}

uint Neutral::getCountFriends() 
{
    return _countFriends;
}

uint Neutral::getCountEnemies() 
{
    return _countEnemies;
}

uint Neutral::getHumanity() 
{
    return _humanity;
}

uint Neutral::getAgression() 
{
    return _agression;
}

void Neutral::setCountFriends(uint countFriends) 
{
    _countFriends = countFriends;
}

void Neutral::setCountEnemies(uint countEnemies) 
{
    _countEnemies = countEnemies;
}

void Neutral::setHumanity(uint humanity) 
{
    _humanity = humanity;
}

void Neutral::setAgression(uint agression) 
{
    _agression = agression;
}

bool Neutral::makeFriends() 
{
    _humanity++;
    _countFriends++;
    uint health = getHealth();
    setHealth(health + 10);
    return true;
}

bool Neutral::makeEnemies() 
{
    _countEnemies++;
    _agression++;
    uint health = getHealth();
    setHealth(health - 5);
    uint damage = getDamage();
    setDamage(damage + 15);
    return true;
}
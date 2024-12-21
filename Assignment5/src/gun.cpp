// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#include "gun.h"

Gun::Gun() {}

uint Gun::getAmmo()
{
    return _ammo;
}

void Gun::setAmmo(uint ammo)
{
    _ammo = ammo;
}
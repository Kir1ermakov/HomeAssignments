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
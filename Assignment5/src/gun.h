// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#ifndef GUN_H
#define GUN_H

#include <sys/types.h>
#define uint unsigned int

class Gun
{
public:
    Gun();
    uint getAmmo();
    void setAmmo(uint ammo);

private:
    uint _ammo;
};

#endif // GUN_H
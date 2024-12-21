// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <sys/types.h>
#include "gun.h"
#include "heart.h"

#define uint unsigned int

class Transformer
{
public:
    Transformer(Gun* gun, const Heart& heart);
    Transformer(Gun* gun, const Heart& heart, uint health, uint energy, uint damage, uint luck);
    uint getHealth();
    uint getEnergy();
    uint getDamage();
    uint getLuck();

    virtual ~Transformer() = default;
    virtual void transform() const;
    virtual void openFire() const;
    virtual void ultra() const;

    void setHealth(uint health);
    void setEnergy(uint energy);
    void setDamage(uint damage);
    void setLuck(uint luck);

    bool shock();
    bool takeDamage();

    bool operator>(const Transformer& other) const;
    bool operator<(const Transformer& other) const;
    bool operator==(const Transformer& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);

private:
    uint _health;
    uint _energy;
    uint _damage;
    uint _luck;
    Gun* _gun;
    Heart _heart;

};

#endif // TRANSFORMER_H
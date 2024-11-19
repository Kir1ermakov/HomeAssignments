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
    ~Transformer();
    uint getHealth();
    uint getEnergy();
    uint getDamage();
    uint getLuck();
    
    void setHealth(uint health);
    void setEnergy(uint energy);
    void setDamage(uint damage);
    void setLuck(uint luck);

    bool shock();
    bool takeDamage();
  
  private:
    uint _health;
    uint _energy;
    uint _damage;
    uint _luck;
    Gun* _gun;
    Heart _heart;
};

#endif // TRANSFORMER_H
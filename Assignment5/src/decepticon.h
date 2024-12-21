// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment5

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "transformer.h"

class Decepticon : public Transformer
{
public:
    Decepticon(Gun* gun, const Heart& heart);

    Decepticon(Gun* gun, const Heart& heart, uint countEnemies, uint agression);

    void transform() const;
    void openFire() const;
    void ultra() const;

    uint getCountEnemies();
    uint getAgression();

    void setCountEnemies(uint countEnemies);
    void setAgression(uint agression);

    bool makeEnemies();

    bool operator>(const Decepticon& other) const;
    bool operator<(const Decepticon& other) const;
    bool operator==(const Decepticon& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Decepticon& d);

private:
    uint _countEnemies;
    uint _agression;
};

#endif // DECEPTICON_H
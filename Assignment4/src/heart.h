// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#ifndef HEART_H
#define HEART_H

#include <string>

class Heart
{
public:
    Heart();

    std::string getNullProtocol();
    void setNullProtocol(std::string nullProtocol);

private:
    std::string _nullProtocol;
};

#endif // HEART_H
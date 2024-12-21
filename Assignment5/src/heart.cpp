// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#include "heart.h"

Heart::Heart() {}

std::string Heart::getNullProtocol()
{
    return _nullProtocol;
}

void Heart::setNullProtocol(std::string nullProtocol)
{
    _nullProtocol = nullProtocol;
}
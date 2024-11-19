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
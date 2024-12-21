// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment4

#include <iostream>
#include "src/transformer.h"
#include "src/autobot.h"
#include "src/gun.h"
#include "src/heart.h"
#include "src/decepticon.h"

int main()
{
    Gun gunT;
    Heart heartT;
    Transformer t1(&gunT, heartT);

    std::cout << "About your Transformer:" << std::endl;
    std::cout << t1 << std::endl << std::endl;

    Transformer t2(&gunT, heartT, 50, 1, 1, 100);

    std::cout << "About your Transformer:" << std::endl;
    std::cout << t2 << std::endl << std::endl;

    if (t1 > t2)
    {
        std::cout << "Transformer 1 is stronger than Transformer 2" << std::endl << std::endl;
    }
    else if (t1 < t2)
    {
        std::cout << "Transformer 1 is weaker than Transformer 2" << std::endl << std::endl;
    }
    else
    {
        std::cout << "They are equal in their splendor and power" << std::endl << std::endl;
    }

    Gun gunA;
    Heart heartA;
    Autobot a1(&gunA, heartA);

    std::cout << a1 << std::endl << std::endl;

    Autobot a2(&gunA, heartA, 5, 50);

    std::cout << a2 << std::endl << std::endl;

    if (a1 > a2)
    {
        std::cout << "Autobot 1 is stronger than Autobot 2" << std::endl << std::endl;
    }
    else if (a1 < a2)
    {
        std::cout << "Autobot 1 is weaker than Autobot 2" << std::endl << std::endl;
    }
    else
    {
        std::cout << "They are equal in their splendor and power" << std::endl << std::endl;
    }

    Gun gunD;
    Heart heartD;
    Decepticon d1(&gunD, heartD);

    std::cout << d1 << std::endl << std::endl;

    Decepticon d2(&gunD, heartD, 0, 10);

    std::cout << d2 << std::endl << std::endl;

    if (d1 > d2)
    {
        std::cout << "Autobot 1 is stronger than Autobot 2" << std::endl << std::endl;
    }
    else if (d1 < d2)
    {
        std::cout << "Autobot 1 is weaker than Autobot 2" << std::endl << std::endl;
    }
    else
    {
        std::cout << "They are equal in their splendor and power" << std::endl << std::endl;
    }

    return 0;
}

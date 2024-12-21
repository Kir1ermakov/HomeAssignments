// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment5

#include <vector>
#include <memory>
#include "autobot.h"
#include "decepticon.h"
#include "transformer.h"

int main() {
    // Явный вызов методов для Autobot и Decepticon
    Autobot a;
    Decepticon d;

    a.transform();
    a.openFire();
    a.ultra();

    d.transform();
    d.openFire();
    d.ultra();

    // Вызов через указатель на базовый класс
    Transformer* t1 = &a;
    Transformer* t2 = &d;

    t1->transform();
    t1->openFire();
    t1->ultra();

    t2->transform();
    t2->openFire();
    t2->ultra();

    std::vector<std::unique_ptr<Transformer>> transformers;
    for (int i = 0; i < 3; ++i) {
        transformers.push_back(std::make_unique<Autobot>());
        transformers.push_back(std::make_unique<Decepticon>());
    }

    for (const auto& t : transformers) {
        t->transform();
        t->openFire();
        t->ultra();
    }

    return 0;
}

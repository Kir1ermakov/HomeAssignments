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

    Gun g;
    Heart h;

    Autobot a(&g, h);
    Decepticon d(&g, h);

    a.transform();
    a.openFire();
    a.ultra();

    d.transform();
    d.openFire();
    d.ultra();

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
        transformers.push_back(std::make_unique<Autobot>(&g, h));
        transformers.push_back(std::make_unique<Decepticon>(&g, h));
        transformers.push_back(std::make_unique<Transformer>(&g, h));
    }

    for (const auto& t : transformers) {
        t->transform();
        t->openFire();
        t->ultra();
    }

    return 0;
}

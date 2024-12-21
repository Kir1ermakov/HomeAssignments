// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment6

#include "../src/wrapper.h"
#include <gtest/gtest.h>

TEST(WrapperSpecialization, Double)
{
    Wrapper<double> w(5, {});
    ASSERT_FALSE(w.foo());
}

// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment6

#include "../src/class1.h"
#include <gtest/gtest.h>

TEST(Class1Test, PositiveNumber)
{
    Class1 c1;
    std::vector<float> v = {1.1f};
    ASSERT_TRUE(c1.bar(5, v));
}

TEST(Class1Test, NegativeNumber)
{
    Class1 c1;
    std::vector<float> v = {1.1f};
    ASSERT_FALSE(c1.bar(-1, v));
}
// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment6

#include "../src/class2.h"
#include <gtest/gtest.h>

TEST(Class2Test, NonEmptyVector)
{
    Class2 c2;
    std::vector<float> v = {2.2f};
    ASSERT_TRUE(c2.bar(0, v));
}

TEST(Class2Test, EmptyVector)
{
    Class2 c2;
    std::vector<float> v;
    ASSERT_FALSE(c2.bar(0, v));
}
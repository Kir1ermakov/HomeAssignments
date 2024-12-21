// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment6

#include "../src/class3.h"
#include <gtest/gtest.h>

TEST(Class3Test, CorrectLength)
{
    Class3 c3;
    std::vector<float> v = {3.3f, 4.4f};
    ASSERT_TRUE(c3.bar(-2, v));
}

TEST(Class3Test, IncorrectLength)
{
    Class3 c3;
    std::vector<float> v = {3.3f};
    ASSERT_FALSE(c3.bar(-2, v));
}
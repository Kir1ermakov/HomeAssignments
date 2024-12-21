#include "wrapper.h"
#include "class1.h"
#include "class2.h"
#include "class3.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(Class1Test, PositiveNumber) {
    Class1 c1;
    std::vector<float> v = {1.1f};
    ASSERT_TRUE(c1.bar(5, v));
}

TEST(Class1Test, NegativeNumber) {
    Class1 c1;
    std::vector<float> v = {1.1f};
    ASSERT_FALSE(c1.bar(-1, v));
}

TEST(Class2Test, NonEmptyVector) {
    Class2 c2;
    std::vector<float> v = {2.2f};
    ASSERT_TRUE(c2.bar(0, v));
}

TEST(Class2Test, EmptyVector) {
    Class2 c2;
    std::vector<float> v;
    ASSERT_FALSE(c2.bar(0, v));
}

TEST(Class3Test, CorrectLength) {
    Class3 c3;
    std::vector<float> v = {3.3f, 4.4f};
    ASSERT_TRUE(c3.bar(-2, v));
}

TEST(Class3Test, IncorrectLength) {
    Class3 c3;
    std::vector<float> v = {3.3f};
    ASSERT_FALSE(c3.bar(-2, v));
}

TEST(WrapperSpecialization, Int) {
    Wrapper<int> w(5, {});
    ASSERT_TRUE(w.foo());
}

TEST(WrapperSpecialization, Double) {
    Wrapper<double> w(5, {});
    ASSERT_FALSE(w.foo());
}


#include "../src/wrapper.h"
#include <gtest/gtest.h>

TEST(WrapperSpecialization, Double)
{
    Wrapper<double> w(5, {});
    ASSERT_FALSE(w.foo());
}

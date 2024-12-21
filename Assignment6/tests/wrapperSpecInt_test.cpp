#include "../src/wrapper.h"
#include <gtest/gtest.h>

TEST(WrapperSpecialization, Int)
{
    Wrapper<int> w(5, {});
    ASSERT_TRUE(w.foo());
}
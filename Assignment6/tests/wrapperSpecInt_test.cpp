#include "wrapper.h"

TEST(WrapperSpecialization, Int) {
    Wrapper<int> w(5, {});
    ASSERT_TRUE(w.foo());
}
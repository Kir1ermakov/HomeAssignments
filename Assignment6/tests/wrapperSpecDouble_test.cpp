#include "wrapper.h"

TEST(WrapperSpecialization, Double) {
    Wrapper<double> w(5, {});
    ASSERT_FALSE(w.foo());
}

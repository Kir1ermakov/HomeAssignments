#include "class3.h"

bool Class3::bar(int n, std::vector<float>& v)
{
    return n == static_cast<int>(v.size()) * -1;
}

int Class3::c_3_1()
{
    return 777;
}
float Class3::c_3_2()
{
    return 6.66f;
}
void Class3::c_3_3() {}

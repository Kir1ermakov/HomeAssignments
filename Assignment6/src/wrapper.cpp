#include "wrapper.h"

template <typename T>
Wrapper<T>::Wrapper(int n, const std::vector<float>& v) : instance(), number(n), data(v) {}

template <typename T>
bool Wrapper<T>::foo()
{
    return instance.bar(number, data);
}

Wrapper<int>::Wrapper(int n, const std::vector<float>& v) : instance(0), number(n), data(v) {}

bool Wrapper<int>::foo()
{
    return true;
}

Wrapper<double>::Wrapper(int n, const std::vector<float>& v) : instance(0.0), number(n), data(v) {}

bool Wrapper<double>::foo()
{
    return false;
}
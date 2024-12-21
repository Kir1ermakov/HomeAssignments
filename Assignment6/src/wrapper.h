#ifndef WRAPPER_H
#define WRAPPER_H

#include <vector>

template <typename T>
class Wrapper {
private:
    T instance;
    int number;
    std::vector<float> data;

public:
    Wrapper(int n, const std::vector<float>& v);
    bool foo();
};

template <>
class Wrapper<int> {
private:
    int instance;
    int number;
    std::vector<float> data;

public:
    Wrapper(int n, const std::vector<float>& v);
    bool foo();
};

template <>
class Wrapper<double> {
private:
    double instance;
    int number;
    std::vector<float> data;

public:
    Wrapper(int n, const std::vector<float>& v);
    bool foo();
};


#endif // WRAPPER_H
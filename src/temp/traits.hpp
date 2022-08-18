#pragma once

template <typename T>
class traits
{
private:
    T a;
    T b;
public:
    traits(T a, T b) : a(a), b(b) {};
    T sum();
};

template<typename T>
class traitsTemplate
{
public:
    static const int is_traits = 0;
};

template<>
class traitsTemplate<int>
{
public:
    static const int is_traits = 1;
};

template<typename T>
inline T traits<T>::sum()
{
    std::cout << traitsTemplate<T>::is_traits;
    return this->a + this->b;
}

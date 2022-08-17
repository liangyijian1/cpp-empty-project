#pragma once
#include <ostream>

template<typename T>
class Complex
{
private:
    T re;
    T im;
public:
    Complex(T re = 0.0, T im = 0.0)
    : re(re), im(im) {};

    T getRE() const;
    T getIM() const;
    
    Complex& operator+(const Complex& c);
    Complex& operator=(const Complex& c);
    
    template<typename T1>
    friend std::ostream& operator<<(std::ostream& os, const Complex<T1>& c);
};

template<typename T>
T Complex<T>::getRE() const
{
    return this->re;
}

template<typename T>
T Complex<T>::getIM() const
{
    return this->im;
}

template<typename T>
Complex<T>& Complex<T>::operator+(const Complex<T>& c)
{
    this->re += c.re;
    this->im += c.im;
    return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator=(const Complex<T>& c)
{
    this->re = c.re;
    this->im = c.im;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& c)
{
    os << c.re << ',' << c.im;
    return os;
}
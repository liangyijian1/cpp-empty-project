#include "Complex.h"

double Complex::getRE()
{
    return this->re;
}

double Complex::getIM()
{
    return this->im;
}

Complex& Complex::operator+(const Complex& c)
{
    this->re += c.re;
    this->im += c.im;
    return *this;
}

Complex& Complex::operator=(const Complex& c)
{
    this->re = c.re;
    this->im = c.im;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.re << ',' << c.im;
    return os;
}
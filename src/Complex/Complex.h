#pragma once
#include <ostream>

class Complex
{
private:
    double re;
    double im;
public:
    Complex(double re = 0.0, double im = 0.0)
    : re(re), im(im) {};

    double getRE();
    double getIM();
    
    Complex& operator+(const Complex& c);
    Complex& operator=(const Complex& c);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};
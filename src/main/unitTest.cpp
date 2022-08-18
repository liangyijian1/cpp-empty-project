#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "pch.h"
#include "Complex.hpp"
#include "traits.hpp"

double complexTest()
{
    Complex<double> a, b(1, 2), c(3, 4);
    a = b + c; // a = 4 6
    std::cout << a << std::endl << std::is_same<Complex<int>, Complex<double>>::value <<std::endl;
    return a.getRE();
}

double traitsTest()
{
    traits<int> a(1, 2);
    a.sum();
    return 0;
}

TEST_CASE("Test") {
    REQUIRE(complexTest() == 4);
    REQUIRE(traitsTest() == 0);
}

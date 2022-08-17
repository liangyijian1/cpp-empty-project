#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "pch.h"
#include "Complex.h"

double complexTest()
{
    Complex<double> a, b(1, 2), c(3, 4);
    a = b + c; // a = 4 6
    std::cout << a << std::endl;
    return a.getRE();
}

TEST_CASE("complexTest") {
    REQUIRE(complexTest() == 4);
}

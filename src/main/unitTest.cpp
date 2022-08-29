#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "pch.h"
#include "Complex.hpp"
#include "traits.hpp"
#include <vector>

using namespace std;

double complexTest()
{
    Complex<double> a, b(1, 2), c(3, 4);
    a = b + c; // a = 4 6
    cout << a << std::endl << is_same<Complex<int>, Complex<double>>::value <<endl;
    return a.getRE();
}

double traitsTest()
{
    traits<int> a(1, 2);
    a.sum();
    return 0;
}

double bing2ndTest()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(9);
    v.push_back(7);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    cout << count_if(v.begin(), v.end(), bind2nd(less<int>(), 5) ) << endl;
    return 1;
}

TEST_CASE("Test") {
    REQUIRE(bing2ndTest() == 1);
    // REQUIRE(complexTest() == 4);
    // REQUIRE(traitsTest() == 0);
}

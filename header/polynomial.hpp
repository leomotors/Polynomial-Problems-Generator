#include <iostream>
#include <string>
#include <vector>

#include "CONSTANT.h"

#ifndef MY_OWN_POLYNOMIAL_CLASS
#define MY_OWN_POLYNOMIAL_CLASS

class Polynomial
{
public:
    int degree;
    std::vector<int> coef;
    Polynomial();
    Polynomial(std::vector<int>);
    void update();
    std::string printPoly();
    Polynomial operator+(const Polynomial&);
    Polynomial operator*(const Polynomial&);
};

#endif
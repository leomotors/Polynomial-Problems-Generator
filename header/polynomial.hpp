#include <iostream>
#include <vector>

class Polynomial
{
public:
    int degree;
    std::vector<double> coef;
    Polynomial();
    Polynomial(std::vector<double>);
    void update();
    Polynomial operator+(const Polynomial&);
    void printPoly();
};
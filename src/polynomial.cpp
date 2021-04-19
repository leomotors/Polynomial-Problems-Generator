#include <iostream>
#include <vector>

#include "../header/polynomial.hpp"

Polynomial::Polynomial()
{
    this->degree = 0;
}

Polynomial::Polynomial(std::vector<double> initArr)
{
    this->degree = initArr.size() - 1;
    this->coef = initArr;
}

void Polynomial::update()
{
    while (this->coef.back())
    {
        this->coef.pop_back();
    }
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    auto fillZero = [](std::vector<double> coef, int target) {
        while (coef.size() < target)
        {
            coef.push_back(0);
        }
        return coef;
    };

    std::vector<double> p1, p2;
    if (this->degree != other.degree)
    {
        if (this->degree > other.degree)
        {
            p1 = fillZero(other.coef, this->degree + 1);
            p2 = this->coef;
        }
        else
        {
            p1 = fillZero(this->coef, other.degree + 1);
            p2 = other.coef;
        }
    }

    std::vector<double> p3;
    if (p1.size() != p2.size())
    {
        throw "wtf is happening";
    }

    int temp_size = p1.size();
    for (int i = 0; i < temp_size; i++)
    {
        p3.push_back(p1[i] + p2[i]);
    }

    Polynomial result(p3);
    return result;
}

void Polynomial::printPoly()
{
    
}
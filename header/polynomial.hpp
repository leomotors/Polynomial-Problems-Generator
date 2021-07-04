#include <string>
#include <vector>

#ifndef MY_OWN_POLYNOMIAL_CLASS
#define MY_OWN_POLYNOMIAL_CLASS

class Polynomial
{
public:
    int degree;
    std::vector<int64_t> coef;
    Polynomial();
    Polynomial(std::vector<int64_t>);
    void update();
    std::string printPoly(bool ignoreCMDIncompatibility = false);
    Polynomial operator+(const Polynomial &);
    Polynomial operator*(const Polynomial &);
};

#endif
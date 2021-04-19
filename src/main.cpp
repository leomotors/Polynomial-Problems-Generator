#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../header/polynomial.hpp"
#include "../header/polyrand.hpp"

int main()
{
    std::vector<int> kk{2,-2};
    Polynomial res = createPolynomial(kk);
    std::cout << res.printPoly() << std::endl;
    return 0;
}
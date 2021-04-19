#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../header/polynomial.hpp"
#include "../header/polyrand.hpp"

int main()
{
    int N;
    std::cout << "Enter degree => ";
    std::cin >> N;
    std::vector<int> p1 = randPoly(N);
    Polynomial res = createPolynomial(p1);
    std::cout << res.printPoly() << std::endl;
    return 0;
}
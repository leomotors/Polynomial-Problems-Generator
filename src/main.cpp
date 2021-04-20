#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "polynomial.hpp"
#include "polyrand.hpp"
#include "generator.hpp"

int main()
{
    std::srand(std::time(0));
    int T;
    std::cout << "Number of polynomial degree 2: ";
    std::cin >> T;
    for (int i = 1; i <= T; i++)
    {
        std::vector<int> p1 = randPoly(2);
        Polynomial res = createPolynomial(p1);
        std::cout << res.printPoly() << std::endl;
    }
    return 0;
}
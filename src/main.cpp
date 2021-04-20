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
        std::vector<std::pair<int, int>> p1 = randPoly(2);
        Polynomial res = createPolynomial(p1);
        std::cout << i << ") Solve " << res.printPoly() << " = 0" << std::endl;
        std::cout << "Roots are ";
        for(std::pair<int,int> root : p1)
        {
            std::cout << root.first<< "/" << root.second << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
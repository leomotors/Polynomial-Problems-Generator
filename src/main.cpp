#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "../header/polynomial.hpp"

#define CONSTANT_LIMIT 20 // * -20 to 19
int main()
{
    std::srand(std::time(0));

    int a = (std::rand() % CONSTANT_LIMIT * 2) - CONSTANT_LIMIT;
    int b = (std::rand() % CONSTANT_LIMIT * 2) - CONSTANT_LIMIT;

    std::vector<int> hehe{a, 1};
    std::vector<int> hehepopo{b, 1};
    Polynomial p1(hehe);
    Polynomial p2(hehepopo);
    Polynomial p3 = p1 * p2;
    std::cout << "Factor " << p3.printPoly() << " : ";
    int a1,a2;
    std::cin >> a1 >> a2;
    if(a1>a2)
    {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }
    if(a>b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if(a1==a && a2==b)
    {
        std::cout << "CORRECT!" << std::endl;
    }
    else
    {
        std::cout << "YOU SUCK! CYKA BLYAT!" << std::endl;
        std::cout << "Correct answer: " << a << " " << b << " daze!" << std::endl;
    }
    return 0;
}
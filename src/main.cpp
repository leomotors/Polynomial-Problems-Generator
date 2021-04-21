#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "polynomial.hpp"
#include "polyrand.hpp"
#include "generator.hpp"
#include "SafeInput.h"

void printMainMenu();

void oldmain()
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
    }
}
int main()
{
    int choice;
    while (true)
    {
        printMainMenu();
        choice = tsi::getInt("Choice: ");
        std::cout << "Got " << choice << std::endl;
        switch (choice)
        {
        case 2:
        default:
            std::cout << "Unknown Choice!" << std::endl;
        }
    }

    return 0;
}

void printMainMenu()
{
    std::cout << "WELCOME TO MY PROGRAM\n";
    std::cout << "[1] Interactive Mode\n";
    std::cout << "[2] Generator Mode\n";
    std::cout << "[0] Exit\n";
    std::cout << std::endl;
}
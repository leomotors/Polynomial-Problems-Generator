#include <iostream>

#include "menu.hpp"

namespace menu
{
    void mainMenu()
    {
        std::cout << "\n=====|MAIN MENU|=====\n";
        std::cout << "[1] Interactive Mode\n";
        std::cout << "[2] Generator Mode\n";
        std::cout << "[3] Settings\n";
        std::cout << "[0] Exit\n";
        std::cout << std::endl;
    }
    void interactiveMenu()
    {
        std::cout << "\n=====|INTERACTIVE MODE|=====\n";
        std::cout << "[1] Test Mode\n";
        std::cout << "[2] Endless Mode\n";
        std::cout << "[3] Time Limit Mode\n";
        std::cout << "[0] Back\n";
        std::cout << std::endl;
    }
}
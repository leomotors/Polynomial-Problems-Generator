#include <iostream>

#include "menu.hpp"

#include "pSettings.hpp"

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
    void interactive()
    {
        std::cout << "\n=====|INTERACTIVE MODE|=====\n";
        std::cout << "[1] Test Mode\n";
        std::cout << "[2] Endless Mode\n";
        std::cout << "[3] Time Limit Mode\n";
        std::cout << "[0] Back\n";
        std::cout << std::endl;
    }
    void settings()
    {
        std::cout << "\n=====|SETTINGS|=====\n";
        std::cout << "[1] Set Numerator Random Range [Current: "
                  << pSettings::getNumRange() << "]\n";
        std::cout << "[2] Set Denominator Random Range [Current: "
                  << pSettings::getDenomRange() << "]\n";
        std::cout << "[3] Activate Cheat Mode [Current : "
                  << (pSettings::cheatModeStatus()
                          ? "ON"
                          : "OFF")
                  << "]\n";
        std::cout << "[4] Activate Verbose Mode [Current : "
                  << (pSettings::verboseModeStatus()
                          ? "ON"
                          : "OFF")
                  << "]\n";
        std::cout << "[0] Back\n";
        std::cout << std::endl;
    }
}
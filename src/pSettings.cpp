#include <iostream>
#include <string>

#include "pSettings.hpp"
#include "SafeInput.hpp"

#include "menu.hpp"

namespace pSettings
{
    int64_t num_range = 20;
    int64_t denom_range = 1;
    bool cheatMode = false;
    bool verboseMode = false;

    void setNumRange(int64_t nr)
    {
        if (nr < 2)
        {
            std::cout << "ERROR: Numerator Range must be at least 2!" << std::endl;
            return;
        }
        num_range = nr;
    }
    void setDenomRange(int64_t dr)
    {
        if (dr < 1)
        {
            std::cout << "ERROR: Denominator Range must be at least 1!" << std::endl;
            return;
        }
        denom_range = dr;
    }
    int64_t getNumRange()
    {
        return num_range;
    }
    int64_t getDenomRange()
    {
        return denom_range;
    }

    bool cheatModeStatus()
    {
        return cheatMode;
    }

    bool verboseModeStatus()
    {
        return verboseMode;
    }

    void page()
    {
        menu::settings();
        int64_t choice = tsi::getInt("Choice: ");
        int64_t nr, dr;
        switch (choice)
        {
        case 1:
            nr = tsi::getInt("Enter New Numerator Random Range: ");
            setNumRange(nr);
            break;
        case 2:
            dr = tsi::getInt("Enter New Denominator Random Range: ");
            setDenomRange(dr);
            break;
        case 3:
            cheatMode = true;
            std::cout << "Cheat Mode Activated, To turn off: Restart Program"
                      << "\n"
                      << "Answer 'MAFS' or 'METH' to make any question correct!"
                      << std::endl;
            break;
        case 4:
            verboseMode = true;
            std::cout << "Verbose Mode Activated, To turn off: Restart Program"
                      << "\n"
                      << "Verbose Mode will express every detail of your PP Factor in time mode!"
                      << std::endl;
            break;
        case 0:
            return;
        default:
            std::cout << "Unknown Choice!" << std::endl;
        }
    }
}
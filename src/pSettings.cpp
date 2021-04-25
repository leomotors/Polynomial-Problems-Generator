#include <iostream>

#include "pSettings.hpp"
#include "SafeInput.hpp"

#include "menu.hpp"

namespace pSettings
{
    int num_range = 20;
    int denom_range = 3;
    void setNumRange(int nr)
    {
        if (nr < 2)
        {
            std::cout << "ERROR: Numerator Range must be at least 2!" << std::endl;
            return;
        }
        num_range = nr;
    }
    void setDenomRange(int dr)
    {
        if (dr < 1)
        {
            std::cout << "ERROR: Denominator Range must be at least 1!" << std::endl;
            return;
        }
        denom_range = dr;
    }
    int getNumRange()
    {
        return num_range;
    }
    int getDenomRange()
    {
        return denom_range;
    }

    void page()
    {
        menu::settings();
        int choice = tsi::getInt("Choice: ");
        int nr, dr;
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
        case 0:
            return;
        default:
            std::cout << "Unknown Choice!" << std::endl;
        }
    }
}
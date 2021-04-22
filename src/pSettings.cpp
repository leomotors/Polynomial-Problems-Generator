#include "pSettings.hpp"
namespace pSettings
{
    int num_range = 20;
    int denom_range = 3;
    void setNumRange(int nr)
    {
        num_range = nr;
    }
    void setDenomRange(int dr)
    {
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

    void SettingsCore()
    {
        
    }
}
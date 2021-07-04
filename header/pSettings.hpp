#ifndef POLYNOMIAL_SETTINGS
#define POLYNOMIAL_SETTINGS

namespace pSettings
{
    void setNumRange(int64_t);
    void setDenomRange(int64_t);
    int64_t getNumRange();
    int64_t getDenomRange();
    bool cheatModeStatus();
    bool verboseModeStatus();
    void page();
}

#endif
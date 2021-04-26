#include <algorithm>
#include <cmath>
#include "performance.hpp"

#include "pSettings.hpp"

namespace pp
{
    int diffFactor()
    {
        int dr = pSettings::getDenomRange();
        int denominatorFactor = std::min(std::max(1, 2 * (dr - 1)), 10) + std::sqrt(std::max(1, dr - 7)) - 1;

        int nr = pSettings::getNumRange();
        int numeratorFactor = std::sqrt(nr);

        return denominatorFactor * numeratorFactor;
    }
}
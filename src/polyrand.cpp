#include <vector>
#include <utility>
#include <cstdlib>
#include <numeric>

#include "polyrand.hpp"

#include "pSettings.hpp"

std::vector<std::pair<int64_t, int64_t>> randPoly(int64_t degree)
{
    int64_t num_range = pSettings::getNumRange();
    int64_t denom_range = pSettings::getDenomRange();
    std::vector<std::pair<int64_t, int64_t>> result;
    for (int64_t i = 0; i < degree; i++)
    {
        int64_t num = (std::rand() % (num_range * 2)) - num_range;
        int64_t denom = (std::rand() % denom_range) + 1;
        if (std::gcd(num, denom) != 1)
        {
            num /= std::gcd(num, denom);
            denom /= std::gcd(num, denom);
        }
        result.push_back(std::make_pair(num, denom));
    }
    return result;
}

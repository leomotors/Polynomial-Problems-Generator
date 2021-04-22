#include <vector>
#include <utility>
#include <cstdlib>
#include <numeric>

#include "polyrand.hpp"
#include "pSettings.hpp"

std::vector<std::pair<int, int>> randPoly(int degree)
{
    int num_range = pSettings::getNumRange();
    int denom_range = pSettings::getDenomRange();
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < degree; i++)
    {
        int num = (std::rand() % (num_range * 2)) - num_range;
        int denom = (std::rand() % denom_range) + 1;
        if (std::gcd(num, denom) != 1)
        {
            num /= std::gcd(num, denom);
            denom /= std::gcd(num, denom);
        }
        result.push_back(std::make_pair(num, denom));
    }
    return result;
}

#include <vector>
#include <cstdlib>

#include "polyrand.hpp"
#include "CONSTANT.h"

std::vector<int> randPoly(int degree)
{
    std::vector<int> result;
    for (int i = 0; i < degree; i++)
    {
        result.push_back((std::rand() % (ROOT_RANGE * 2)) - ROOT_RANGE);
    }
    return result;
}

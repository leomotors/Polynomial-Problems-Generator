#include <vector>
#include <utility>

#include "polynomial.hpp"

#ifndef POLYNOMIAL_GENERATOR
#define POLYNOMIAL_GENERATOR
namespace PolyGenerator
{
    Polynomial random(int);
    Polynomial getCurrPoly();
    std::vector<std::pair<int, int>> getCurrRoots();
};

#endif
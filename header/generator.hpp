#include <vector>
#include <utility>

#include "polynomial.hpp"

#ifndef POLYNOMIAL_GENERATOR
#define POLYNOMIAL_GENERATOR
namespace PolyGenerator
{
    Polynomial random(int64_t);
    Polynomial getCurrPoly();
    std::vector<std::pair<int64_t, int64_t>> getCurrRoots();
};

#endif
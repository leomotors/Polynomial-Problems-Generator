#include <vector>

#include "polynomial.hpp"

Polynomial createPolynomial(std::vector<int> roots)
{
    int count = roots.size();
    std::vector<int> base_vec({-roots[0], 1});
    Polynomial base(base_vec);
    for (int i = 1; i < count; i++)
    {
        std::vector<int> temp_vec({-roots[i], 1});
        Polynomial temp(temp_vec);
        base = base * temp;
    }
    return base;
}
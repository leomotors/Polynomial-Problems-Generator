#include <vector>
#include <utility>

#include "polynomial.hpp"

Polynomial createPolynomial(std::vector<std::pair<int, int>> roots)
{
    int count = roots.size();
    std::vector<int> base_vec({-roots[0].first, roots[0].second});
    Polynomial base(base_vec);
    for (int i = 1; i < count; i++)
    {
        std::vector<int> temp_vec({-roots[i].first, roots[i].second});
        Polynomial temp(temp_vec);
        base = base * temp;
    }
    return base;
}
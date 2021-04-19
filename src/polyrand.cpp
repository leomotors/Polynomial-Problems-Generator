#include "../header/polyrand.hpp"

std::vector<int> randPoly(int degree)
{
    std::srand(std::time(NULL));
    std::vector<int> result;
    for (int i = 0; i < degree; i++)
    {
        result.push_back((std::rand() % (ROOT_RANGE * 2)) - ROOT_RANGE);
    }
    return result;
}

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
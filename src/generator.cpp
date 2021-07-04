#include <vector>
#include <utility>

#include "generator.hpp"

#include "polynomial.hpp"
#include "polyrand.hpp"

namespace PolyGenerator
{
    Polynomial curr_poly;
    std::vector<std::pair<int64_t, int64_t>> curr_roots;

    Polynomial random(int64_t degree)
    {
        std::vector<std::pair<int64_t, int64_t>> roots = randPoly(degree);

        int64_t count = roots.size();
        std::vector<int64_t> base_vec({-roots[0].first, roots[0].second});
        Polynomial base(base_vec);
        for (int64_t i = 1; i < count; i++)
        {
            std::vector<int64_t> temp_vec({-roots[i].first, roots[i].second});
            Polynomial temp(temp_vec);
            base = base * temp;
        }
        curr_poly = base;
        curr_roots = roots;
        return base;
    }

    Polynomial getCurrPoly()
    {
        return curr_poly;
    }

    std::vector<std::pair<int64_t, int64_t>> getCurrRoots()
    {
        return curr_roots;
    }
}

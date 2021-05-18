#include <string>
#include <unordered_map>

#include "unicode.hpp"

namespace uni
{
    std::unordered_map<int, std::string> dict{
        {2, "²"},
        {3, "³"},
        {4, "⁴"},
        {5, "⁵"},
        {6, "⁶"},
        {7, "⁷"},
        {8, "⁸"},
        {9, "⁹"}};

    std::string getSS(int n)
    {
        if (n <= 1)
            return "";

#ifndef _WIN32
        if (n < 10)
            return dict[n];
#endif
        return std::to_string(n);
    }
}
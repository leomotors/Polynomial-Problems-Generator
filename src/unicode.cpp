#include <string>
#include <unordered_map>

#include "unicode.hpp"

namespace uni
{
#if defined(_WIN32)
    bool isWindows = true;
#else
    bool isWindows = false;
#endif

    std::unordered_map<int, std::string> dict{
        {2, "²"},
        {3, "³"},
        {4, "⁴"},
        {5, "⁵"},
        {6, "⁶"},
        {7, "⁷"},
        {8, "⁸"},
        {9, "⁹"}};

    std::string getSS(int n, bool ignoreCMDIncompatibility)
    {
        if (n <= 1)
            return "";

        if (n < 10 && (!isWindows || ignoreCMDIncompatibility))
            return dict[n];

        return "^" + std::to_string(n);
    }
}
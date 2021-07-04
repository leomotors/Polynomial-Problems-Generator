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

    std::unordered_map<int64_t, std::string> dict{
        {0, "⁰"},
        {1, "¹"},
        {2, "²"},
        {3, "³"},
        {4, "⁴"},
        {5, "⁵"},
        {6, "⁶"},
        {7, "⁷"},
        {8, "⁸"},
        {9, "⁹"}};

    std::string getSS(int64_t n, bool ignoreCMDIncompatibility)
    {
        if (n <= 1)
            return "";

        if (!isWindows || ignoreCMDIncompatibility)
        {
            std::string numstr;
            std::string nums = std::to_string(n);
            for (char s : nums)
                numstr.append(dict[s - '0']);
            return numstr;
        }

        return "^" + std::to_string(n);
    }
}
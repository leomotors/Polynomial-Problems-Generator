#include <vector>
#include <string>

#include "utilsMethod.hpp"

std::vector<std::string> splitStr(std::string str, char spliter)
{
    int ssize = str.size();
    std::vector<std::string> splited_str;
    int index = 0;
    std::string substrtemp;
    while (index < ssize)
    {
        if (str[index] == spliter)
        {
            splited_str.push_back(substrtemp);
            substrtemp = "";
            index++;
            continue;
        }
        substrtemp.push_back(str[index]);
        index++;
    }
    splited_str.push_back(substrtemp);
    return splited_str;
}

std::string rootsToStr(std::vector<std::pair<int, int>> roots_dup)
{
    std::string result_str;

    std::vector<std::pair<int, int>> roots = drop_dupl(roots_dup);
    int roots_count = roots.size();

    for (int i = 0; i < roots_count; i++)
    {
        std::pair<int, int> root = roots[i];
        result_str += std::to_string(root.first);
        if (root.second != 1)
        {
            result_str += "/";
            result_str += std::to_string(root.second);
        }
        result_str += ", ";
    }
    result_str.pop_back();
    result_str.pop_back();

    return result_str;
}

std::vector<std::pair<int, int>> drop_dupl(std::vector<std::pair<int, int>> roots_dup)
{
    std::vector<std::pair<int, int>> roots;
    for (unsigned int i = 0; i < roots_dup.size(); i++)
    {
        bool alreadyIn = false;
        for (unsigned int j = 0; j < roots.size(); j++)
        {
            if (roots[j] == roots_dup[i])
            {
                alreadyIn = true;
                break;
            }
        }
        if (!alreadyIn)
            roots.push_back(roots_dup[i]);
    }

    return roots;
}

double factorial(int n)
{
    if (n == 1)
        return 1.0;
    return n * factorial(n - 1);
}

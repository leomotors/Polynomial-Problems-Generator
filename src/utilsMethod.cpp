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

std::string rootsToStr(std::vector<std::pair<int, int>> roots)
{
    std::string result_str;
    int roots_count = roots.size();

    for(int i =0;i<roots_count;i++)
    {
        std::pair<int,int> root = roots[i];
        result_str += std::to_string(root.first);
        if(root.second != 1)
        {
            result_str += "/";
            result_str += std::to_string(root.second);
        }
        result_str+= ", ";
    }
    result_str.pop_back();
    result_str.pop_back();

    return result_str;
}
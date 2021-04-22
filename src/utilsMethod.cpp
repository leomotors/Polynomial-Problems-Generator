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
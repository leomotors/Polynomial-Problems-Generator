#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "grader.hpp"

#include "utilsMethod.hpp"
#include "pSettings.hpp"

bool isAnswer(std::vector<std::pair<int, int>> roots_dup, std::vector<std::string> submission)
{
    if (pSettings::cheatModeStatus() && (submission[0] == "MAFS" || submission[0] == "METH"))
    {
        std::cout << "Hey! That's cheating!" << std::endl;
        return true;
    }

    std::vector<std::pair<int, int>> roots = drop_dupl(roots_dup);

    if (roots.size() != submission.size())
        return false;

    for (unsigned int i = 0; i < submission.size(); i++)
    {
        std::string thissubm = submission[i];
        std::pair<int, int> convertedsubm;
        std::vector<std::string> splited = splitStr(thissubm, '/');
        if (splited.size() < 2)
            splited.push_back("1");

        int thisCorrect = false;
        for (unsigned int j = 0; j < roots.size(); j++)
        {
            bool num = splited[0] == std::to_string(roots[j].first);
            bool denom = splited[1] == std::to_string(roots[j].second);
            if (num && denom)
            {
                thisCorrect = true;
                break;
            }
        }

        if (!thisCorrect)
            return false;
    }

    return true;
}
#include <algorithm>
#include <cmath>
#include <iostream>

#include "performance.hpp"

#include "pSettings.hpp"
#include "utilsMethod.hpp"

namespace pp
{
    double diffFactor(int degree)
    {
        int dr = pSettings::getDenomRange();
        double denominatorFactor = std::min(std::max(1, 2 * (dr - 1)), 10) + std::sqrt(std::max(1, dr - 7)) - 1;

        int nr = pSettings::getNumRange();
        double numeratorFactor = std::sqrt(nr);

        double degreeFactor = factorial(degree) / 2;
        return denominatorFactor * numeratorFactor * degreeFactor;
    }

    double timepp(int correct, int miss, int injurytime, int gameTime, int pDegree)
    {
        double DiffFactor = diffFactor(pDegree);
        double injuryTimePP = 0;
        int totalQuestion = correct + miss;

        double expectedScore = gameTime / DiffFactor;

        double answeredFactor = correct / expectedScore;

        if (injurytime > 0)
        {
            correct -= 1;
            answeredFactor = correct / expectedScore;
            double bonustime = (double)std::max(1, 10 - injurytime);
            double injuryPPFactor = std::sqrt((bonustime / 10.00) + std::pow(3.00, -3.00 * bonustime));
            injuryTimePP = 0.5 * injuryPPFactor * std::sqrt(DiffFactor) * answeredFactor;
        }

        double missPenalty = (miss < 1) ? 1
                                        : 0.975 * std::pow((1 - std::pow((double)miss / (totalQuestion), 0.7)), (miss / (totalQuestion - miss)));

        double e2 = 2.717 * 2.717;
        double gameTimeFactor = std::max(1.00, std::log((gameTime / 30.00) - 1 + e2) / std::log(e2));

        double BasePP = answeredFactor;

        double DifficultyFactor = std::log(DiffFactor) / std::log(e2);
        DifficultyFactor = (DifficultyFactor < 1) ? std::cbrt(DifficultyFactor)
                                                  : std::pow(DifficultyFactor, 1.35);

        double totalPP = BasePP * gameTimeFactor * missPenalty + injuryTimePP;

        if (pSettings::verboseModeStatus())
            std::cout << "\nVerbose:"
                      << "\n"
                      << "Base PP: " << BasePP << "\n"
                      << "Difficulty Factor: " << DifficultyFactor << "\n"
                      << "Game Time Factor: " << gameTimeFactor << "\n"
                      << "Miss Penalty: " << missPenalty << "\n"
                      << "Bonus PP from Injury Time Question: " << injuryTimePP
                      << std::endl;

        return totalPP;
    }
}
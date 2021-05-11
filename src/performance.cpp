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
        if (correct == 0 || (correct <= 1 && injurytime > 0))
        {
            if (pSettings::verboseModeStatus())
                std::cout << "\nVerbose: There is no correct answer during game, so no score." << std::endl;
            return 0;
        }

        double DiffFactor = diffFactor(pDegree);
        double injuryTimePP = 0;
        int totalQuestion = correct + miss;

        double expectedScore = gameTime / DiffFactor;

        double answeredFactor = correct / expectedScore;

        double e2 = 2.717 * 2.717;
        double DiffBonus = std::log(DiffFactor) / std::log(e2);
        DiffBonus = (DiffBonus < 1) ? std::cbrt(DiffBonus)
                                    : std::pow(DiffBonus, 1.35);
        double gameTimeFactor = std::max(1.00, std::log((gameTime / 15.00) - 1 + e2) / std::log(e2));

        if (injurytime > 0)
        {
            correct -= 1;
            answeredFactor = correct / expectedScore;
            double bonustime = (double)std::max(1, 10 - injurytime);
            double injuryPPFactor = std::sqrt((bonustime / 10.00) + std::pow(3.00, -3.00 * bonustime));
            injuryTimePP = injuryPPFactor * DiffBonus * answeredFactor / std::pow(correct, 1.5);
        }

        double missPenalty = (miss < 1) ? 1
                                        : 0.975 * std::pow((1 - std::pow((double)miss / (totalQuestion), 0.7)), (miss / (totalQuestion - miss)));

        double BasePP = answeredFactor * 2;

        double totalPP = BasePP * DiffBonus * gameTimeFactor * missPenalty + injuryTimePP;

        if (pSettings::verboseModeStatus())
            std::cout << "\nVerbose:"
                      << "\n"
                      << "Base PP: " << BasePP << "\n"
                      << "Difficulty Bonus: " << DiffBonus << "\n"
                      << "Game Time Factor: " << gameTimeFactor << "\n"
                      << "Miss Penalty: " << missPenalty << "\n"
                      << "Bonus PP from Injury Time Question: " << injuryTimePP
                      << std::endl;

        return totalPP;
    }
}

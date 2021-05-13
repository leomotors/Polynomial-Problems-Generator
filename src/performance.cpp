#include <algorithm>
#include <cmath>
#include <iostream>

#include "performance.hpp"

#include "pSettings.hpp"
#include "utilsMethod.hpp"

namespace pp
{
    double e1t5 = std::pow(2.717, 1.5);
    double e2 = 2.717 * 2.717;

    double diffFactor(int degree)
    {
        int dr = pSettings::getDenomRange();
        double denominatorFactor = std::min(std::max(1, 2 * (dr - 1)), 10) + std::sqrt(std::max(1, dr - 7)) - 1;

        int nr = pSettings::getNumRange();
        double numeratorFactor = std::sqrt(nr);

        double degreeFactor = factorial(degree) / 2;
        return denominatorFactor * numeratorFactor * degreeFactor;
    }

    double performanceCalc(int correct, int miss, int injurytime, int gameTime, int pDegree, bool considerGameTime)
    {
        if (correct == 0 || (correct <= 1 && injurytime > 0))
        {
            if (pSettings::verboseModeStatus())
                std::cout << "\nVerbose: There is no correct answer during game, so no score." << std::endl;
            return 0;
        }

        double DiffFactor = diffFactor(pDegree);

        int totalQuestion = correct + miss;

        double expectedScore = gameTime / DiffFactor;

        double answeredFactor = correct / expectedScore;
        double BasePP = answeredFactor * 2;

        double DiffBonus = std::log(DiffFactor) / std::log(e2);
        DiffBonus = (DiffBonus < 1) ? std::cbrt(DiffBonus)
                                    : std::pow(DiffBonus, 1.35);

        double gameTimeFactor;
        if (considerGameTime)
            gameTimeFactor = std::log((gameTime / 45.00) - 1 + e1t5) / std::log(e1t5);
        else
            gameTimeFactor = 1.00;

        double injuryPPFactor = 0;
        if (injurytime > 0)
        {
            correct -= 1;
            answeredFactor = correct / expectedScore;
            double bonustime = (double)std::max(1, 10 - injurytime);
            injuryPPFactor = std::sqrt((bonustime / 10.00) + std::pow(3.00, -3.00 * bonustime)) * std::pow(gameTimeFactor, 3.0) / 2.00;
        }

        double missPenalty = (miss < 1) ? 1
                                        : 0.975 * std::pow((1 - std::pow((double)miss / (totalQuestion), 0.7)), (miss / (totalQuestion - miss)));

        double totalBasePP = BasePP * DiffBonus * gameTimeFactor * missPenalty;
        double injuryPPBonus = injuryPPFactor * totalBasePP / std::pow(correct, 0.93);
        double totalPP = totalBasePP + injuryPPBonus;
        if (pSettings::verboseModeStatus())
            std::cout << "\nVerbose:"
                      << "\n"
                      << "Base PP: " << BasePP << "\n"
                      << "Difficulty Bonus: " << DiffBonus << "\n"
                      << "Game Time Factor: " << gameTimeFactor << "\n"
                      << "Miss Penalty: " << missPenalty << "\n"
                      << "Bonus PP from Injury Time Question: " << injuryPPBonus
                      << std::endl;

        return totalPP;
    }
}

#include <algorithm>
#include <cmath>
#include "performance.hpp"

#include "pSettings.hpp"

namespace pp
{
    double diffFactor()
    {
        int dr = pSettings::getDenomRange();
        double denominatorFactor = std::min(std::max(1, 2 * (dr - 1)), 10) + std::sqrt(std::max(1, dr - 7)) - 1;

        int nr = pSettings::getNumRange();
        double numeratorFactor = std::sqrt(nr);

        return denominatorFactor * numeratorFactor;
    }

    double timepp(int correct, int miss, int injurytime, int gameTime)
    {
        double DiffFactor = diffFactor();
        double injuryTimePP = 0;

        double expectedScore = gameTime / DiffFactor;

        double answeredFactor = correct / expectedScore;


        if (injurytime > 0)
        {
            correct -= 1;
            double bonustime = (double)std::max(1, 10 - injurytime);
            double injuryPPFactor = std::sqrt((bonustime / 10.00) + std::pow(3.00, -3.00 * bonustime));
            injuryTimePP = 0.5 * injuryPPFactor * DiffFactor * answeredFactor;
        }

        double missPenalty = std::pow(0.95, (double)miss * expectedScore / correct);

        double e2 = 2.717 * 2.717;
        double gameTimeFactor = std::max(1.00, std::log((gameTime / 30.00) - 1 + e2) / std::log(e2));

        double BasePP = correct * DiffFactor;

        double totalPP = BasePP * answeredFactor * gameTimeFactor * missPenalty + injuryTimePP;

        return totalPP;
    }
}
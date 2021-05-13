#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "interactive.hpp"
#include "SafeInput.hpp"

#include "polynomial.hpp"
#include "utilsMethod.hpp"
#include "generator.hpp"
#include "grader.hpp"
#include "performance.hpp"
#include "pSettings.hpp"

double testMode()
{
    int questions = tsi::getInt("Number of question: ");
    int pDegree = tsi::getInt("Degree of Polynomial: ");

    if (pDegree < 2)
    {
        std::cout << "WARNING: Polynomial degree must be at least 2!" << std::endl;
        return -1;
    }

    int score = 0;
    int wrong = 0;
    const std::time_t start = std::time(nullptr);

    for (int i = 1; i <= questions; i++)
    {
        Polynomial res = PolyGenerator::random(pDegree);
        std::cout << i << ") Solve " << res.printPoly() << " = 0" << std::endl;
        std::string submission = tsi::getString("Your answer: ");

        std::vector<std::string> splited_submission = splitStr(submission, ' ');
        if (isAnswer(PolyGenerator::getCurrRoots(), splited_submission))
        {
            std::cout << "CORRECT!" << std::endl;
            score++;
        }
        else
        {
            std::cout << "YOU SUCK BLYAT!" << std::endl;
            std::cout << "CORRECT IS "
                      << rootsToStr(PolyGenerator::getCurrRoots()) << std::endl;
            wrong++;
        }
        std::cout << std::endl;
    }
    const std::time_t end = std::time(nullptr);
    int time_used = end - start;

    double performancePoint = pp::performanceCalc(score, wrong, 0, time_used, pDegree, false);

    std::cout << "\nResult: You scored " << score << " out of " << questions << "!\n"
              << std::endl;
    std::cout << "Performance Point: "
              << performancePoint
              << std::endl;
    std::cout
        << "Average Difficulity of Test you've done : "
        << pp::diffFactor(pDegree) << std::endl;
    return (double)score / questions;
}

int endlessMode()
{
    int pDegree = tsi::getInt("Degree of Polynomial: ");
    int gachaFactor = 3;
    int innerGachaFactor = 5;

    if (pDegree < 2)
    {
        std::cout << "WARNING: Polynomial degree must be at least 2!" << std::endl;
        return -1;
    }

    int score = 0;
    while (true)
    {
        std::cout << "CURRENT SCORE: " << score << std::endl;
        std::cout << "CURRENT DIFFICULITY: " << pp::diffFactor(pDegree) << std::endl;

        Polynomial res = PolyGenerator::random(pDegree);
        std::cout << "Solve " << res.printPoly() << " = 0" << std::endl;
        std::string submission = tsi::getString("Your answer: ");

        std::vector<std::string> splited_submission = splitStr(submission, ' ');
        if (isAnswer(PolyGenerator::getCurrRoots(), splited_submission))
        {
            std::cout << "CORRECT!" << std::endl;
            score++;

            // * Adding Difficulity
            if (std::rand() % 10 < gachaFactor) // * 30% Chance and increasing
            {
                gachaFactor = 3;
                if (std::rand() % 100 < innerGachaFactor) // * 5% Chance and increasing
                {
                    innerGachaFactor = 5;
                    pSettings::setDenomRange(pSettings::getDenomRange() + 1);
                }
                else
                {
                    innerGachaFactor += 3;
                    pSettings::setNumRange(pSettings::getNumRange() * ((double)(std::rand() % 5) / 10 + 1));
                }
            }
            else
                gachaFactor += 1;
        }
        else
        {
            std::cout << "YOU LOSE! Nice Job" << std::endl;
            std::cout << "CORRECT IS "
                      << rootsToStr(PolyGenerator::getCurrRoots()) << "\n"
                      << std::endl;
            std::cout << "Your Score is " << score << "\n"
                      << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    std::cout << "Final Average Difficulity of you've reached : "
              << pp::diffFactor(pDegree) << std::endl;
    return score;
}

#define PENALTY_TIME 5

int timelimitMode()
{
    int timelimit = tsi::getInt("Enter Time: ");
    int pDegree = tsi::getInt("Enter Degree of Polynomial: ");

    if (timelimit < 30)
    {
        std::cout << "WARNING: Too Small Time! Time must be at least 30 secs!" << std::endl;
        return -1;
    }

    if (pDegree < 2)
    {
        std::cout << "WARNING: Polynomial degree must be at least 2!" << std::endl;
        return -1;
    }

    auto TimeElapsed = [](const std::time_t from) {
        return std::time(nullptr) - from;
    };
    const std::time_t start = std::time(nullptr);

    int score = 0;
    int penalty = 0;
    bool lastIsCorrect = false;
    bool hasInjuryTime;
    while (true)
    {
        int timeLeft = timelimit - TimeElapsed(start) - penalty;
        if (timeLeft <= 0)
        {
            hasInjuryTime = (timeLeft == 0) ? false : true;
            std::cout << std::endl;
            break;
        }

        std::cout << "CURRENT SCORE: " << score << std::endl;
        std::cout << "TIME LEFT: " << timeLeft << std::endl;
        std::cout << std::endl;

        Polynomial res = PolyGenerator::random(pDegree);
        std::cout << "Solve " << res.printPoly() << " = 0" << std::endl;
        std::string submission = tsi::getString("Your answer: ");

        std::vector<std::string> splited_submission = splitStr(submission, ' ');
        if (isAnswer(PolyGenerator::getCurrRoots(), splited_submission))
        {
            std::cout << "CORRECT!" << std::endl;
            score++;
            lastIsCorrect = true;
        }
        else
        {
            std::cout << "W R O N G!" << std::endl;
            std::cout << "CORRECT IS "
                      << rootsToStr(PolyGenerator::getCurrRoots()) << "\n"
                      << std::endl;
            penalty += PENALTY_TIME;
            lastIsCorrect = false;
        }
        std::cout << std::endl;
    }

    std::cout << "TIME'S UP!" << std::endl;
    std::cout << "Within time of " << timelimit << " secs. ";

    int injuryTime = 0;
    if (score > 0)
    {
        if (lastIsCorrect && hasInjuryTime)
        {
            injuryTime = TimeElapsed(start) - timelimit + penalty;
            std::cout << "Your Score is " << score - 1 << " +1("
                      << injuryTime << " secs)\n"
                      << std::endl;
        }
        else
            std::cout << "Your Score is " << score << "\n"
                      << std::endl;
    }

    else
        std::cout << "Your Score is 0\n"
                  << std::endl;

    std::cout << "You answered wrong " << penalty / PENALTY_TIME << " questions." << std::endl;
    double thisPP = pp::performanceCalc(score, penalty / PENALTY_TIME, injuryTime, timelimit, pDegree, true);

    std::cout << "Average Difficulity of Test you've done : "
              << pp::diffFactor(pDegree) << "\n"
              << std::endl;
    std::cout << "Performance Point: " << thisPP
              << (pSettings::cheatModeStatus()
                      ? " (With Cheat Mode On)"
                      : "")
              << std::endl;
    return score;
}
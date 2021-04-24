#include <iostream>
#include <string>

#include "interactive.hpp"
#include "SafeInput.hpp"

#include "polynomial.hpp"
#include "utilsMethod.hpp"
#include "generator.hpp"
#include "grader.hpp"

double testMode()
{
    int questions = tsi::getInt("Number of question: ");
    int difficulity = tsi::getInt("Degree of Polynomial: ");
    int score = 0;

    for (int i = 1; i <= questions; i++)
    {
        Polynomial res = PolyGenerator::random(difficulity);
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
            std::cout << "CORRECT IS " << rootsToStr(PolyGenerator::getCurrRoots()) << std::endl;
        }
        std::cout << std::endl;
    }

    return (double)score / questions;
}

int endlessMode()
{
    int difficulity = tsi::getInt("Degree of Polynomial: ");
    int score = 0;
    while (true)
    {
        std::cout << "CURRENT SCORE: " << score << std::endl;
        Polynomial res = PolyGenerator::random(difficulity);
        std::cout << "Solve " << res.printPoly() << " = 0" << std::endl;
        std::string submission = tsi::getString("Your answer: ");

        std::vector<std::string> splited_submission = splitStr(submission, ' ');
        if (isAnswer(PolyGenerator::getCurrRoots(), splited_submission))
        {
            std::cout << "CORRECT!" << std::endl;
            score++;
        }
        else
        {
            std::cout << "YOU LOSE! Nice Job" << std::endl;
            std::cout << "CORRECT IS " << rootsToStr(PolyGenerator::getCurrRoots()) << std::endl;
            std::cout << "Your Score is " << score << "\n"
                      << std::endl;
            return score;
        }
        std::cout << std::endl;
    }
}
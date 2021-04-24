#include <iostream>
#include <string>

#include "interactive.hpp"
#include "SafeInput.hpp"

#include "polynomial.hpp"
#include "utilsMethod.hpp"
#include "generator.hpp"
#include "grader.hpp"

void testMode()
{
    int questions = tsi::getInt("Number of question: ");
    int difficulity = tsi::getInt("Degree of Polynomial: ");

    for (int i = 1; i <= questions; i++)
    {
        Polynomial res = PolyGenerator::random(difficulity);
        std::cout << i << ") Solve " << res.printPoly() << " = 0" << std::endl;
        std::string submission = tsi::getString("Your answer: ");

        std::vector<std::string> splited_submission = splitStr(submission, ' ');
        if (isAnswer(PolyGenerator::getCurrRoots(), splited_submission))
            std::cout << "CORRECT!" << std::endl;
        else
        {
            std::cout << "YOU SUCK BLYAT!" << std::endl;
            std::cout << "CORRECT IS " << rootsToStr(PolyGenerator::getCurrRoots()) << std::endl;
        }
        std::cout << std::endl;
    }
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "polynomial.hpp"
#include "polyrand.hpp"
#include "generator.hpp"
#include "grader.hpp"
#include "utilsMethod.hpp"
#include "SafeInput.hpp"
#include "pSettings.hpp"

void printMainMenu();
void interactiveMode();
void testMode();
void endlessMode();
void timelimitMode();
void generateMode();

int main()
{
    std::srand(std::time(0));
    int choice;
    while (true)
    {
        printMainMenu();
        choice = tsi::getInt("Choice: ");
        switch (choice)
        {
        case 1:
            interactiveMode();
            break;
        case 2:
            generateMode();
            break;
        case 0:
            std::cout << "GOODBYE JOJO!!!" << std::endl;
            return 0;
        default:
            std::cout << "Unknown Choice!" << std::endl;
        }
    }

    return 0;
}

void printMainMenu()
{
    std::cout << "\n=====|MAIN MENU|=====\n";
    std::cout << "[1] Interactive Mode\n";
    std::cout << "[2] Generator Mode\n";
    std::cout << "[3] Settings\n";
    std::cout << "[0] Exit\n";
    std::cout << std::endl;
}

void interactiveMode()
{
    std::cout << "\n=====|INTERACTIVE MODE|=====\n";
    std::cout << "[1] Test Mode\n";
    std::cout << "[2] Endless Mode\n";
    std::cout << "[3] Time Limit Mode\n";
    std::cout << "[0] Back\n";
    std::cout << std::endl;

    int choice = tsi::getInt("Your Choice: ");
    switch (choice)
    {
    case 1:
        testMode();
        break;
    case 0:
        return;
    default:
        std::cout << "Unknown Choice!" << std::endl;
    }
}

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

void generateMode()
{
    std::string ofile_location = "./generated/";
    std::string ofile_name = tsi::getString("Enter Output File name: ");
    ofile_location += ofile_name;
    ofile_location += ".txt";
    std::ofstream OutFile(ofile_location);

    int difficulity = tsi::getInt("Degree of Polynomial: ");
    int T = tsi::getInt("Number of polynomial: ");
    for (int i = 1; i <= T; i++)
    {
        Polynomial res = PolyGenerator::random(difficulity);
        OutFile << i << ") Solve " << res.printPoly() << " = 0" << std::endl;
    }

    std::cout << "Successfully generated file" << std::endl;
    OutFile.close();
}
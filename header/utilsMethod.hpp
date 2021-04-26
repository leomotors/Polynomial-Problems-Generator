#include <vector>
#include <string>

#ifndef UTILS_METHOD
#define UTILS_METHOD

std::vector<std::string> splitStr(std::string,char);
std::string rootsToStr(std::vector<std::pair<int, int>>);
std::vector<std::pair<int, int>> drop_dupl(std::vector<std::pair<int, int>>);
double factorial(int);

#endif
#include <vector>
#include <string>

#ifndef UTILS_METHOD
#define UTILS_METHOD

std::vector<std::string> splitStr(std::string, char);
std::string rootsToStr(std::vector<std::pair<int64_t, int64_t>>, bool _JSON = false);
std::vector<std::pair<int64_t, int64_t>> drop_dupl(std::vector<std::pair<int64_t, int64_t>>);
double factorial(int64_t);

#endif
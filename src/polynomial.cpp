#include <vector>
#include <string>
#include <utility>
#include <cmath>

#include "polynomial.hpp"

#include "unicode.hpp"

Polynomial::Polynomial()
{
    this->degree = 0;
}

Polynomial::Polynomial(std::vector<int64_t> initArr)
{
    this->degree = initArr.size() - 1;
    this->coef = initArr;
}

void Polynomial::update()
{
    while (!this->coef.back())
    {
        this->coef.pop_back();
    }
}

std::string Polynomial::printPoly(bool ignoreCMDIncompatibility)
{
    int64_t max_degree = this->degree;
    std::string resultstr;
    std::vector<std::pair<int64_t, int64_t>> term_list;

    for (int64_t i = max_degree; i >= 0; i--)
    {
        if (this->coef[i])
        {
            term_list.push_back(std::make_pair(coef[i], i));
        }
    }

    if (term_list[0].first != 1)
        resultstr += std::to_string(term_list[0].first);
    if (term_list[0].second)
    {
        resultstr += "x";
        resultstr += uni::getSS(term_list[0].second, ignoreCMDIncompatibility);
    }

    int64_t term_count = term_list.size();
    for (int64_t i = 1; i < term_count; i++)
    {
        std::pair<int64_t, int64_t> term = term_list[i];
        if (term.first > 0)
            resultstr += " + ";
        else
            resultstr += " - ";
        if (std::abs(term.first) != 1 || term.second == 0)
            resultstr += std::to_string(std::abs(term.first));
        if (term.second >= 1)
        {
            resultstr += "x";
            resultstr += uni::getSS(term.second, ignoreCMDIncompatibility);
        }
    }

    return resultstr;
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    auto fillZero = [](std::vector<int64_t> coef_temp, int target) {
        while ((int64_t)coef_temp.size() < target)
        {
            coef_temp.push_back(0);
        }
        return coef_temp;
    };

    std::vector<int64_t> p1, p2;
    if (this->degree != other.degree)
    {
        if (this->degree > other.degree)
        {
            p1 = fillZero(other.coef, this->degree + 1);
            p2 = this->coef;
        }
        else
        {
            p1 = fillZero(this->coef, other.degree + 1);
            p2 = other.coef;
        }
    }
    else
    {
        p1 = this->coef;
        p2 = other.coef;
    }

    std::vector<int64_t> p3;
    if (p1.size() != p2.size())
    {
        throw "wtf is happening";
    }

    int64_t temp_size = p1.size();
    for (int64_t i = 0; i < temp_size; i++)
    {
        p3.push_back(p1[i] + p2[i]);
    }

    Polynomial result(p3);
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    int64_t max_degree = this->degree + other.degree;
    std::vector<int64_t> resultcoef;
    for (int64_t i = 0; i <= max_degree; i++)
        resultcoef.push_back(0);

    for (int64_t i = 0; i <= this->degree; i++)
    {
        for (int64_t j = 0; j <= other.degree; j++)
        {
            resultcoef[i + j] += (this->coef[i] * other.coef[j]);
        }
    }

    Polynomial result(resultcoef);
    return result;
}
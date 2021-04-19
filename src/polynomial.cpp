#include "../header/polynomial.hpp"

Polynomial::Polynomial()
{
    this->degree = 0;
}

Polynomial::Polynomial(std::vector<int> initArr)
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

std::string Polynomial::printPoly()
{
    int temp_iter = this->degree;
    std::string resultstr;
    for (int i = temp_iter; i >= 2; i--)
    {
        if (this->coef[i])
        {
            if (this->coef[i] != 1)
                resultstr.append(std::to_string(this->coef[i]));
            resultstr.append("x^");
            resultstr.append(std::to_string(i));
            resultstr.append(" + ");
        }
    }
    if (degree >= 1 && this->coef[1] && this->coef[0])
    {
        if (this->coef[1] != 1)
            resultstr.append(std::to_string(this->coef[1]));
        resultstr.append("x + ");
        resultstr.append(std::to_string(this->coef[0]));
    }
    else
    {
        if (degree >= 1 && this->coef[1])
        {
            resultstr.append(std::to_string(this->coef[1]));
            resultstr.append("x");
        }
        if (this->coef[0])
        {
            resultstr.append(std::to_string(this->coef[0]));
        }
    }

    if (resultstr[resultstr.size() - 2] == '+')
    {
        resultstr.pop_back();
        resultstr.pop_back();
        resultstr.pop_back();
    }

    return resultstr;
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    auto fillZero = [](std::vector<int> coef_temp, int target) {
        while ((int)coef_temp.size() < target)
        {
            coef_temp.push_back(0);
        }
        return coef_temp;
    };

    std::vector<int> p1, p2;
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

    std::vector<int> p3;
    if (p1.size() != p2.size())
    {
        throw "wtf is happening";
    }

    int temp_size = p1.size();
    for (int i = 0; i < temp_size; i++)
    {
        p3.push_back(p1[i] + p2[i]);
    }

    Polynomial result(p3);
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    int max_degree = this->degree + other.degree;
    std::vector<int> resultcoef;
    for (int i = 0; i <= max_degree; i++)
        resultcoef.push_back(0);

    for (int i = 0; i <= this->degree; i++)
    {
        for (int j = 0; j <= other.degree; j++)
        {
            resultcoef[i + j] += (this->coef[i] * other.coef[j]);
        }
    }

    Polynomial result(resultcoef);
    return result;
}
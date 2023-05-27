#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        assert(denominator != 0);
    }

    Fraction(const Fraction &copy)
        : m_numerator{copy.m_numerator}, m_denominator{copy.m_denominator}
    {
        std::cout << "Copy constructor called\n";
    }

    Fraction &operator=(const Fraction &fraction);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
};

std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

Fraction &Fraction::operator=(const Fraction &fraction)
{
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;
    return *this;
}

int main()
{
    Fraction f1{5, 3};
    Fraction f2{7, 2};
    Fraction f3{9, 5};
    f1 = f2 = f3;
    std::cout << f1 << '\n' << f2 << '\n' << f3 << '\n';
    return 0;
}
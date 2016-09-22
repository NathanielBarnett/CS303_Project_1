#include "term.h"

Term::Term(int expo, int coeff)
{
    exponent = expo;
    coefficient = coeff; 
}

int Term::get_coeff() const
{
    return coefficient;
}

int Term::get_expo() const
{
    return exponent;
}

void Term::set_coeff(int coeff)
{
    coefficient = coeff;
}

void Term::set_expo(int expo)
{
    exponent = expo;
}

bool operator==(const Term &t1, const Term &t2)
{
    t1.exponent == t2.exponent;
}

bool operator>(const Term& t1, const Term& t2)
{
    return t1.exponent > t2.exponent;
}

bool operator<(const Term& t1, const Term& t2)
{
    return t1.exponent < t2.exponent;
}

const Term& Term::operator= (const Term& m_term)
{
    this->exponent = m_term.exponent;
    this->coefficient = m_term.coefficient;
    return *this;
}

const Term Term::operator+(const Term& m_term)
{
    Term temp;

    if (temp.exponent = m_term.exponent)
    {
        temp.coefficient = this->coefficient + m_term.coefficient;
        return temp;
    }
    //else give error. work on throw.
}

ostream& operator<<(ostream& out, const Term& m_term)
{
    if (m_term.exponent == 0)
    {
        out << m_term.coefficient;
    }

    else if (m_term.exponent == 1)
    {
        out << m_term.coefficient << "x";
    }

    else
    {
        out << m_term.coefficient << "x^" << m_term.exponent;
    }
}

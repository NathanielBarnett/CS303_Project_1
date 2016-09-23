//Term Class that contains the exponent and coefficient.
//Also holds comparison operators to compare exponents.
#include "Term.h"
#include <sstream>
using namespace std;


void Term::ConvertTerm(string S_Term, const string& delim)
{

	int i = 0, temp_coeff = 0, temp_expo = 0;
	int pos = S_Term.find_first_of(delim);
	string s_coeff = S_Term.substr(i, pos);
	string s_expo = S_Term.substr(pos + 1);
	istringstream coeff_buf(s_coeff), expo_buf(s_expo);
	char var1, var2;

	// Exponent calculations
	if (expo_buf >> var1)
		expo_buf >> temp_expo;
	else
		temp_expo = 1;
	// coefficient calculations
	coeff_buf >> var1;
	if (var1 == '-' || var1 == '+')
	{

		if (coeff_buf >> var2)
		{
			coeff_buf.putback(var2);
			coeff_buf.putback(var1);
			coeff_buf >> temp_coeff;
		}
		else
		{
			switch (var1)
			{
			case '-':
				temp_coeff = -1;
				break;
			case '+':
				temp_coeff = 1;
				break;
			}
		}
	}
	else if (var1 == '\0')
	{
		temp_coeff = 1;
	}
	else
	{
		coeff_buf.putback(var1);
		coeff_buf >> temp_coeff;
	}
	*this = Term(temp_expo, temp_coeff);
}


Term::Term(int expo, int coeff)
{
	exponent = expo;
	coefficient = coeff;
}

int Term::get_coeff() const
{
	return coefficient;
}

int Term::get_exponent() const
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
	return t1.exponent == t2.exponent;
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
	else
		throw exception("BACON");
}

ostream& operator<<(ostream& out, const Term& m_term)
{
	if (m_term.exponent == 0)
	{
		out << m_term.coefficient;
		return out;
	}

	else if (m_term.exponent == 1)
	{
		out << m_term.coefficient << "x";
		return out;
	}

	else
	{
		out << m_term.coefficient << "x^" << m_term.exponent;
		return out;
	}
}
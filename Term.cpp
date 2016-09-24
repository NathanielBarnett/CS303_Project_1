//Students : Nathaniel Barnett    | Adam Bergman         | Urvish Shah
//Email    : nabgz8@mail.umkc.edu | ambd5d@mail.umkc.edu | ujs8t2@mail.umkc.edu

//Professor: Dr. Mohammad Kuhail
//Class    : CS 303 - Data Structures 

//Date     : 9/25/2016
//Project  : Polynomial Addition Program (Project 1B)

//File name:Term.cpp
#include "Term.h"
#include <sstream>
using namespace std;

void Term::ConvertTerm(string S_Term, const string& delim)
{

	int i = 0, temp_coeff = 0, temp_expo = 0;
	int pos = S_Term.find_first_of(delim);//pos will equal the first location of a specified delim
	string s_coeff = S_Term.substr(i, pos);//s_coeff will become the coeff variable for S_Term
	string s_expo = S_Term.substr(pos + 1);//s_expo will become the expo variable for S_Term
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


Term::Term(int expo, int coeff)//Constructor
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

bool operator==(const Term &t1, const Term &t2)//Returns true if they equal each other, false otherwise.
{
	return t1.exponent == t2.exponent;
}

bool operator>(const Term& t1, const Term& t2)//Returns true if t1's exponent is larger, false otherwise.
{
	return t1.exponent > t2.exponent;
}

bool operator<(const Term& t1, const Term& t2)//Returns true if t1's exponent is smaller, false otherwise.
{
	return t1.exponent < t2.exponent;
}

const Term& Term::operator=(const Term& m_term)//Creates a copy of the term passed and returns it.
{
	this->exponent = m_term.exponent;
	this->coefficient = m_term.coefficient;
	return *this;
}

const Term Term::operator+(const Term& m_term)//? need help understanding, ask Urvish.
{
	Term temp;

	if (temp.exponent == m_term.exponent)
	{
		temp.coefficient = this->coefficient + m_term.coefficient;
		return temp;
	}
	else
		throw exception("BACON");
}

ostream& operator<<(ostream& out, const Term& m_term)//Makes Terms printable to the screen.
{
	if (m_term.exponent == 0)//If Term has no exponent, return only the coeff
	{
		out << m_term.coefficient;
		return out;
	}

	else if (m_term.exponent == 1)//If Terms exponent is 1, return coeff followed by 'x'
	{
		out << m_term.coefficient << "x";
		return out;
	}

	else//Return coeff + 'x' + exponent.
	{
		out << m_term.coefficient << "x^" << m_term.exponent;
		return out;
	}
}

//Students : Nathaniel Barnett    | Adam Bergman         | Urvish Shah
//Email    : nabgz8@mail.umkc.edu | ambd5d@mail.umkc.edu | ujs8t2@mail.umkc.edu

//Professor: Dr. Mohammad Kuhail
//Class    : CS 303 - Data Structures 

//Date     : 9/25/2016
//Project  : Polynomial Addition Program (Project 1B)

//File name:Polynomial.cpp
#include "Polynomial.h"
#include <sstream>

// Function definitions
const Polynomial Polynomial::operator+(const Polynomial& rhs_Poly)
{
	// Identify max number of terms
	size_t counter;
	if (L_Poly.size() >= rhs_Poly.L_Poly.size())
		counter = L_Poly.size();
	else if (L_Poly.size() < rhs_Poly.L_Poly.size())
		counter = rhs_Poly.L_Poly.size();
	return rhs_Poly;//???????Ask Urvish

}

void Polynomial::AddTerm(string S_Term) 
{
	Term N_Term;
	N_Term.ConvertTerm(S_Term);

	// if L_Poly is empty, push onto L_Poly and exit
	if (L_Poly.size() == 0)
	{
		L_Poly.push_back(N_Term);
		return;
	}

	list<Term>::iterator itr;
	int flag = 0;
	for (itr = L_Poly.begin(); itr != L_Poly.end(); itr++)
	{
		flag++;
		if (itr->get_exponent() > N_Term.get_exponent() && flag != L_Poly.size())//If size is only 1, keep going.
		{
			continue;
		}
		else if (itr->get_exponent() < N_Term.get_exponent())
		{
			L_Poly.insert(itr, N_Term);
			return;
		}
		else if (itr->get_exponent() == N_Term.get_exponent())
		{
			*itr = *itr + N_Term;
			return;
		}
		else
		{
			L_Poly.push_back(N_Term);
			return;
		}
	}
}

void Poly_Parse(const string& s, Polynomial& Poly, const string& delim)
{
	// variables for use in function
	int i = 0;
	int pos = s.find_first_of(delim);
	string sub_str;
	char carrot = '^';

	while (pos != string::npos)
	{
		// if there is a positive or negative sign as the first character of the polynomial string
		if (pos == 0) {
			pos = s.find_first_of(delim, pos + 1);
		}

		// grab the substring from the source string
		sub_str = s.substr(i, pos - i);
		i = pos++;

		// if the substring has the '^' char, and the '^' char is last char in string
		// then grab the exponent from source string and concatenate onto substring
		if (sub_str.find(carrot) != -1 && sub_str.back() == carrot)
		{
			pos = s.find_first_of(delim, pos + 1);
			sub_str = sub_str + s.substr(i, pos - i);
			i = pos++;
		}

		// push the substring onto the list
		Poly.AddTerm(sub_str);

		// update pos to the next position of delim in source string
		pos = s.find_first_of(delim, pos);

		// if pos is at end of source string, push back the rest of source string
		if (pos == string::npos)
			Poly.AddTerm(s.substr(i, s.length() - i));
	}
}

const ostream& operator<<(ostream& output, const Polynomial& rhs_Poly)
{
	list<Term>::iterator itr;
	for (itr = rhs_Poly.begin(); itr != rhs_Poly.end(); itr++)
	{
		out << itr->get_exponent() << itr->get_coeff();
	}
	return out;
}

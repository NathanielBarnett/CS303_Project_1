#pragma once
//Term Class that contains the exponent and coefficient.
//Also holds comparison operators to compare exponents.
#include "Term.h"
#include <string>
#include <iostream>
using namespace std;

class Term {

private:

	int exponent;
	int coefficient;

public:

	Term() {}//Default constructor

	Term(int expo, int coeff);//Construcotr with private variables

	friend bool operator==(const Term &t1, const Term &t2);//Checks if two terms are the same.

	friend bool operator>(const Term &t1, const Term &t2);//Checks which term has greater variables.

	friend bool operator<(const Term& t1, const Term& t2);//Checks which term has lesser vairalbes.

	friend ostream& operator<<(ostream& out, const Term& m_term);//Allows terms to be output.

	const Term& operator=(const Term& m_term);//Assigns variables from one term to equal another.

	const Term operator+(const Term& m_term);//Adds terms 

	void ConvertTerm(string S_Term, const string& delim = "X");

	int get_coeff() const;
	int get_exponent() const;
	void set_coeff(int coeff);
	void set_expo(int expo);

};

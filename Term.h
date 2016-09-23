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

	Term() {}

	Term(int expo, int coeff);

	friend bool operator==(const Term &t1, const Term &t2);

	friend bool operator>(const Term &t1, const Term &t2);

	friend bool operator<(const Term& t1, const Term& t2);

	friend ostream& operator<<(ostream& out, const Term& m_term);

	const Term& operator=(const Term& m_term);

	const Term operator+(const Term& m_term);

	void ConvertTerm(string S_Term, const string& delim = "X");

	int get_coeff() const;
	int get_exponent() const;
	void set_coeff(int coeff);
	void set_expo(int expo);

};
//Students : Nathaniel Barnett    | Adam Bergman         | Urvish Shah
//Email    : nabgz8@mail.umkc.edu | ambd5d@mail.umkc.edu | ujs8t2@mail.umkc.edu

//Professor: Dr. Mohammad Kuhail
//Class    : CS 303 - Data Structures 

//Date     : 9/25/2016
//Project  : Polynomial Addition Program (Project 1B)

//File name:Polynomial.h
#pragma once
#include <list>
#include <iostream>
#include <string>
#include "Term.h"
using namespace std;

class Polynomial {

private:
	list<Term> L_Poly;

public:
	Polynomial() { ; }
	// Copy Constructor ASK URVISH ??
	//Polynomial(const Polynomial& Current_Poly);
	
	const Polynomial operator+(const Polynomial& rhs_Poly);//Adds polynomials 
	
	friend const ostream& operator<<(ostream& output, const Polynomial& rhs_Poly);//Needs implementation!!
	
	//function to add Term element onto polynomial list
	void AddTerm(string S_Term);

};

// Utility function for polynomial class
void Poly_Parse(const string& s, Polynomial& Poly, const string& delim = "-+");

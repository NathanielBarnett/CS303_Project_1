#pragma once
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


    int get_coeff() const;
    int get_expo() const;
    void set_coeff(int coeff);
    void set_expo(int expo);
    
};
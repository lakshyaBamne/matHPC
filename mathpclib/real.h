#pragma once

#include<iostream>
#include<cmath>

using namespace std;

class Real{
private:
    long double value;
public:
    // class constructor - default value is 0
    Real(long double user_value=0){
        this->value = user_value;
    }

    // basic arithmetic operations on the real number
    Real operator+(const Real &r);
    Real operator-(const Real &r);
    Real operator*(const Real &r);
    Real operator/(const Real &r);

    // overloading the input stream and output stream operators
    friend ostream & operator<<(ostream &out, const Real &r);    
    friend istream & operator>>(istream &in, Real &r);    

    // typecast to integer variable with the same amount of memory
    operator uint64_t();
    operator double();
    operator long double();
    
};
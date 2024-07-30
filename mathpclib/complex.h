#pragma once

#include<iostream>
#include<cmath>

#include "real.h"

using namespace std;

class Complex{
private:
    double real_part;
    double imaginary_part;

public:
    // constructor
    Complex(long double realval=0, long double imgval=0){
        this->real_part = realval;
        this->imaginary_part = imgval;
    }

    // Overloading the input stream and output stream operators
    friend ostream & operator<<(ostream &out, const Complex &c);
    friend istream & operator>>(istream &in, Complex &c);

    // Overloading the basic arithmetic operators for the complex numbers
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);

    // method calculates the modulus of the complex number
    Real mod();

};


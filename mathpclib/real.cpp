#include<iostream>
#include<cmath>
#include<string>

#include "real.h"

using namespace std;

// Basic Arithmetic operations
Real Real::operator+(const Real &r){
    Real rsum(this->value + r.value);

    return rsum;
}

Real Real::operator-(const Real &r){
    Real rdif(this->value - r.value);

    return rdif;
}

Real Real::operator*(const Real &r){
    Real rmul(this->value * r.value);

    return rmul;
}

Real Real::operator/(const Real &r){
    // here we also need to check for the division by zero exception
    try{
        if(r.value == 0){
            throw r.value;
        }

        // if there is no division by zero exception we can proceed to divide the reals
        Real rdiv(this->value/r.value);
        return rdiv;
    }
    catch(double rval){
        if(rval == 0){
            cout << "[ERROR] division by zero while dividing matHPC real type" << endl;
        }
        else{
            cout << "[INTERNAL ERROR] unexpected behavior in source code" << endl;
        }
    }
    catch (...){
        cout << "[UNKNOWN EXCEPTION] default exception raised while division of matHPC real type" << endl;
    }

    Real NaN(sqrtl(-1));
    return NaN;
}

// Overloading the input stream and output stream operators for the real data type
ostream & operator<<(ostream &out, const Real &r){
    out << r.value;
    return out;
}

istream & operator>>(istream &in, Real &r){
    in >> r.value;
    return in;
}

// Typecasting operations
Real::operator uint64_t(){
    return uint64_t(this->value);
}

Real::operator double(){
    return this->value;
}

Real::operator long double(){
    return (long double)this->value;
}

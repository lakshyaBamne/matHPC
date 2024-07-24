#pragma once

#include<iostream>
#include<vector>
#include<cmath>

#include "real.h"

using namespace std;

class Col{
private:
    vector<Real> array;

public:
    // Methods to initialize the column vector
    // 1) Initialize from an STL vector<doubke>
    Col(const vector<double>& vec = {}){
        // convert each element of the input vector to an object of the matHPT real type
        for(auto i : vec){
            Real entry(i);
            this->array.push_back(entry);
        }
    }

    // 2) Initialize by reading entries from a .mathpccol file

    // overloading the output stream operator for the column vector
    friend ostream & operator<<(ostream &out, const Col &col);

    // member access operator for the column using 0 indexings
    Real operator[](int i);

    // Col [] Col -> Col operators (element by element operations)
    Col operator+(Col &col);
    Col operator-(Col &col);
    Col operator*(Col &col);
    Col operator/(Col &col);

    // Col [] Row -> Matrix operators

};

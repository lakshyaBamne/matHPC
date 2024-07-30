#pragma once

#include<iostream>
#include<vector>
#include<cmath>

#include "real.h"
#include "row.h"

using namespace std;

class Row; // Forward declaration of the Row class

class Col{
private:
    vector<Real> array;

public:
    // Methods to initialize the column vector
    // 1) Initialize from an STL vector<long double>
    Col(const vector<long double>& vec = {}){
        // convert each element of the input vector to an object of the matHPT real type
        for(auto i : vec){
            Real entry(i);
            this->array.push_back(entry);
        }
    }

    // 2) Initialize from a vector of Real objects
    Col(const vector<Real>& vec = {}){
        for(auto i : vec){
            this->array.push_back(i);
        }
    }

    // 3) Create a column of zeroes of the given size
    Col(int elements=0, Real value=0){
        for(int i=0 ; i<elements ; i++){
            this->array.push_back(value);
        }
    }

    // overloading the output stream operator for the column vector
    friend ostream & operator<<(ostream &out, const Col &col);

    // Transpose operation
    Row T();

    // member access operator for the column using 0 indexings
    Real operator[](int i);

    // Col [] Col -> Col operators (element by element operations)
    Col operator+(Col &col);
    Col operator-(Col &col);
    Col operator*(Col &col);
    Col operator/(Col &col);

    // Col [] Row -> Matrix operators

    // Utility functions on the column vector
    vector<int> shape();
    void push_back(Real value);

};

#pragma once

#include<iostream>
#include<vector>
#include<cmath>

#include "real.h"
#include "column.h"

using namespace std;

class Col; // Forward declaration of the Col class

class Row{
private:
    vector<Real> array;

public:
    // Methods to initialize the row vector
    // 1) Initialize from an STL vector<long double>
    Row(const vector<long double>& vec = {}){
        // convert each element of the input vector to an object of the matHPT real type
        for(auto i : vec){
            Real entry(i);
            this->array.push_back(entry);
        }
    }

    // 2) Initialize from a vector of Real objects
    Row(const vector<Real>& vec = {}){
        for(auto i : vec){
            this->array.push_back(i);
        }
    }

    // 3) Create a row of zeroes of the given size
    Row(int elements=0, Real value=0){
        for(int i=0 ; i<elements ; i++){
            this->array.push_back(value);
        }
    }

    // overloading the output stream operator for the column vector
    friend ostream & operator<<(ostream &out, const Row &row);

    // member access operator for the column using 0 indexings
    Real operator[](int i);

    // Transpose operator
    Col T();

    // Row * Real -> Row operator (scalar vector multiplication)
    Row operator*(Real &real);

    // Row [] Row -> Row operators (element by element operations)
    Row operator+(Row &row);
    Row operator-(Row &row);
    Row operator*(Row &row);
    Row operator/(Row &row);

    // Row [] Col -> Real operator (Inner Product)
    Real operator*(Col &col);

    // Utility functions for the Row vector
    vector<int> shape();
    void push_back(Real value);

};
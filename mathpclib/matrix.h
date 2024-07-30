#pragma once

#include<iostream>
#include<vector>
#include<cmath>

#include "real.h"
#include "complex.h"
#include "column.h"
#include "row.h"

using namespace std;

// forward declarations of the classes used in the class Matrix
class Row;
class Col;

class Matrix{
private:
    vector<Row> matrix;

public:

    // Class constructors

    // 1) Create a zero matrix of given rows and columns
    Matrix(int row=0, int col=0){
        Row r(col, 0);

        for(int i=0 ; i<row ; i++){
            this->matrix.push_back(r);
        }        
    }

    // 2) Create a matrix from a given 2D stl-vector

    // Basic operators overloading on matrix operations
    Row operator[](int i);

    // Output stream operator overload for matrix
    friend ostream & operator<<(ostream &out, Matrix &matrix);

    vector<int> shape();
    void push_back(Row row);

};
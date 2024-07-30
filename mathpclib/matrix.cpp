#include<iostream>
#include<vector>
#include<cmath>

#include "matrix.h"

using namespace std;

// Operator overloads for basic operations on two matrices
Row Matrix::operator[](int i){
    return this->matrix[i];
}

// Output stream overloading for a matrix
ostream & operator<<(ostream &out, Matrix &matrix){

    if(matrix.shape()[0] == 0){
        // empty matrix
        out << "MATRIX:- (empty)" << endl;
    }
    else{
        out << "MATRIX:-" << endl;

        for(int i=0 ; i<matrix.shape()[0] ; i++){
            out << "[" << i << "]" << matrix[i] << endl;
        }
    }

    return out;

}

// Utility functions for matrix
vector<int> Matrix::shape(){
    if((int)this->matrix.size() == 0){
        return {0,0};
    }

    return {(int)this->matrix.size(), (int)this->matrix[0].shape()[1]};
}

void Matrix::push_back(Row row){
    // first we need to check if the size of the already existing rows
    // and the given row are same or not

    try{
        if(this->shape()[0]!=0 && this->shape()[1]!=row.shape()[1]){
            throw 0;
        }

        this->matrix.push_back(row);
    }
    catch(int size){
        if(size == 0){
            cout << "[ERROR] size mismatch while adding row to matrix" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN ERROR] unknown error while adding row to matrix" << endl;
    }
}

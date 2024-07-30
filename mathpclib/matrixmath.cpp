#include<iostream>
#include<vector>
#include<cmath>

#include "matrixmath.h"

using namespace std;

Real inner_product(Row &row, Col &col){
    int row_len = row.shape()[1];
    int col_len = col.shape()[0];

    Real ip = 0;
    
    try{
        if(row_len != col_len){
            throw 0;
        }

        // if the shapes are same we can perform the inner product
        for(int i=0 ; i<row_len ; i++){
            ip = ip + row[i]*col[i];
        }
    }
    catch(int size){
        if(size == 0){
            cout << "[ERROR] size mismatch while doing inner product" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN ERROR] unknown error encountered while performing inner product" << endl;
    }

    return ip;
}


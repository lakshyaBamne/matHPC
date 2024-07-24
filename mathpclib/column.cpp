#include<iostream>
#include<vector>

#include "column.h"
#include "real.h"

using namespace std;

// output stream operator
ostream & operator<<(ostream &out, const Col &col){
    out << "ColumnT: ";
    for(int i=0 ; i<col.array.size()-1 ; i++){
        out << col.array[i] << ", ";
    }
    out << col.array.back() << endl;

    return out;
}

// member access operator overload
Real Col::operator[](int i){
    Real val(this->array[i]);
    
    return val;
}

Col Col::operator+(Col &col){
    vector<double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != col.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] + col[i];
        }
    }
    catch(int exception){
        if(exception == 0){
            cout << "[ERROR] unequal size of column vectors" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN EXCEPTION] raised while performing col-col addition" << endl;
    }

    // returns a zero vector of size = this->array.size()
    Col colsum(vec);
    return colsum;

}

Col Col::operator-(Col &col){
    vector<double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != col.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] - col[i];
        }
    }
    catch(int exception){
        if(exception == 0){
            cout << "[ERROR] unequal size of column vectors" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN EXCEPTION] raised while performing col-col subtraction" << endl;
    }

    // returns a zero vector of size = this->array.size()
    Col coldif(vec);
    return coldif;

}

Col Col::operator*(Col &col){
    vector<double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != col.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] * col[i];
        }
    }
    catch(int exception){
        if(exception == 0){
            cout << "[ERROR] unequal size of column vectors" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN EXCEPTION] raised while performing col-col multiplication" << endl;
    }

    // returns a zero vector of size = this->array.size()
    Col colmul(vec);
    return colmul;

}

Col Col::operator/(Col &col){
    vector<double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != col.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] / col[i];
        }
    }
    catch(int exception){
        if(exception == 0){
            cout << "[ERROR] unequal size of column vectors" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN EXCEPTION] raised while performing col-col division" << endl;
    }

    // returns a zero vector of size = this->array.size()
    Col coldiv(vec);
    return coldiv;

}

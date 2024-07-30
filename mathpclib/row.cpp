#include<iostream>
#include<vector>

#include "real.h"
#include "row.h"

using namespace std;

// output stream operator
ostream & operator<<(ostream &out, const Row &row){
    out << "ROW: ";

    try{
        if(row.array.size() == 0){
            throw 0;
        }
        
        // if the size of the row is not zero output it
        for(int i=0 ; i<row.array.size()-1 ; i++){
            out << row.array[i] << ", ";
        }
        out << row.array.back() << endl;
    }
    catch(int size){

    }
    catch(...){
        cout << "[UNKNOWN ERROR] while printing row" << endl;
    }
    
    return out;
}

// member access operator overload
Real Row::operator[](int i){
    Real val(this->array[i]);
    
    return val;
}

// Row transpose
Col Row::T(){
    Col col(this->array);
    return col;
}

// Row [] Real -> Row operator (Scalar vector multiplication)
Row Row::operator*(Real &real){
    Row op(0);

    for(auto i : this->array){
        op.push_back(i*real);
    }

    return op;
}


// Row [] Row -> Row element wise operations overloaded
Row Row::operator+(Row & row){
    vector<long double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != row.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] + row[i];
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
    Row rowsum(vec);
    return rowsum;
}

Row Row::operator-(Row & row){
    vector<long double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != row.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] - row[i];
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
    Row rowdif(vec);
    return rowdif;
}

Row Row::operator*(Row & row){
    vector<long double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != row.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] * row[i];
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
    Row rowmul(vec);
    return rowmul;
}

Row Row::operator/(Row & row){
    vector<long double> vec(this->array.size(), 0);

    try{
        // both column vectors should have the same length
        if(this->array.size() != row.array.size()){
            throw 0;
        }

        for(int i=0 ; i<this->array.size() ; i++){
            vec[i] = this->array[i] / row[i];
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
    Row rowdiv(vec);
    return rowdiv;
}

// Row [] Col -> Real operations (Inner product)
Real Row::operator*(Col &col){
    int row_len = this->shape()[1];
    int col_len = col.shape()[0];

    Real ip = 0;
    
    try{
        if(row_len != col_len){
            throw 0;
        }

        // if the shapes are same we can perform the inner product
        for(int i=0 ; i<row_len ; i++){
            ip = ip + this->array[i]*col[i];
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


// Utility functions for the row vector
vector<int> Row::shape(){
    return {1, (int)this->array.size()};
}

void Row::push_back(Real value){
    this->array.push_back(value);
}

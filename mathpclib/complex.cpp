#include<iostream>
#include<cmath>

#include "complex.h"

using namespace std;

// Overloading input stream and output stream operators for complex numbers
ostream & operator<<(ostream &out, const Complex &c){
    out << c.real_part << "+i" << c.imaginary_part;
    return out;
}

istream & operator>>(istream &in, Complex &c){
    cout << "real part: ";
    in >> c.real_part;
    cout << "imaginary part: ";
    in >> c.imaginary_part;

    return in;
}

Complex Complex::operator+(const Complex &c){
    Complex csum(this->real_part+c.real_part, this->imaginary_part+c.imaginary_part);
    return csum;
}

Complex Complex::operator-(const Complex &c){
    Complex cdif(this->real_part-c.real_part, this->imaginary_part-c.imaginary_part);
    return cdif;
}

Complex Complex::operator*(const Complex &c){
    Complex cmul;

    cmul.real_part = this->real_part*c.real_part - this->imaginary_part*c.imaginary_part;
    cmul.imaginary_part = this->real_part*c.imaginary_part + this->imaginary_part*c.real_part;

    return cmul;
}

Complex Complex::operator/(const Complex &c){
    Complex cdiv;

    try{
        double denom = pow(c.real_part,2) + pow(c.imaginary_part,2);

        if( denom == 0 ){
            throw denom;
        }

        // if exception is not raised we can proceed with the division
        cdiv.real_part = (this->real_part*c.real_part + this->imaginary_part*c.imaginary_part)/denom;
        cdiv.imaginary_part = (this->imaginary_part*c.real_part - this->real_part*c.imaginary_part)/denom;

        return cdiv;
    }
    catch(double exception){
        if(exception == 0){
            cout << "[ERROR] division by zero error while dividing matHPC complex type" << endl;
        }
    }
    catch(...){
        cout << "[UNKNOWN EXCEPTION] unknown exception occured while division of matHPC complex type" << endl;
    }

    cdiv.real_part = sqrtf(-1);
    cdiv.imaginary_part = sqrtf(-1);

    return cdiv;
}

// Method to calculate the modulus of the complex number
// this will always be a positive real number
Real Complex::mod(){
    Real modval(sqrt(pow(this->real_part,2)+pow(this->imaginary_part,2)));
    return modval;
}

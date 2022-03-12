//
//  complex.cpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 25.02.2022.
//

#include "complex.hpp"
using namespace std;

Complex::Complex(){
    this->_real = 0;
    this->_imag = 0;
}

Complex::Complex(int a, int b){
    this->_real = a;
    this->_imag = b;
}

Complex::Complex(const Complex& complex){
    this->_real = complex._real;
    this->_imag = complex._imag;
}

ostream & operator << (ostream &out, Complex &complex){
    out << complex._real << " + " << complex._imag << "i";
    
    return out;
}

istream & operator >> (istream &in,  Complex &complex){
    
    cout << "Enter real and imaginary part:" << endl;
    
    in >> complex._real >> complex._imag;
    
    return in;
}

const int Complex::real(){
    return this->_real;
}

const int Complex::imag(){
    return this->_imag;
}


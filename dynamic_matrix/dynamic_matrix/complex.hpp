//
//  complex.hpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 25.02.2022.
//

/*  Complex numbers class to use as type in Matrix  */

#ifndef complex_hpp
#define complex_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

class Complex{
    
    public:
    
        int _real;
        int _imag;
        
        Complex();
        Complex(int a, int b);
        Complex(const Complex& complex);
        
        friend ostream &operator<< (ostream &output, Complex &complex);
        friend istream &operator>> (istream &input, Complex &cconplex);
    
        Complex& operator+(const Complex& other);
        Complex& operator-(const Complex& other);
        Complex& operator*(const Complex& other);
        Complex& operator/(const Complex& other);
    
        const int real();
        const int imag();
        
};

#endif /* complex_hpp */

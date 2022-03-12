//
//  complex.hpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 25.02.2022.
//

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
    
        const int real();
        const int imag();
    
//        Complex& operator=(const Complex& other);
        
};

#endif /* complex_hpp */

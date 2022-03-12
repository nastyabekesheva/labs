//
//  matrix.hpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 22.02.2022.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include "complex.hpp"
using namespace std;

//        Parent class
template<typename T>
class Matrix{
    protected:
    
        int _rows;
        int _cols;
        
        T **_matrix;
    
    public:

//        Default constructor
        Matrix();
//        Parameter constructor
        Matrix(int _rows, int _cols);
//        Copy constructor
        Matrix(const Matrix<T> &other);
//        Destructor
        virtual ~Matrix();
    
//        Custom methods
        const int row();
        const int col();
        void getSize();
        void getElement(unsigned int value);

//        Stream overloading
        template<typename U>
        friend ostream & operator << (ostream &out, const Matrix<U> &matrix);
        template<typename U>
        friend istream & operator >> (istream &in,  Matrix<T> &matrix);
    
//        Operator overloading for access
        T& operator()(const unsigned int& i, const unsigned int& j);
        const T& operator()(const unsigned int& i, const unsigned int& j) const;
        T& operator [](unsigned i);
    
//        Operator overloading methods for two matricies
        Matrix<T> operator+(const Matrix<T>& other);
        Matrix<T> operator-(const Matrix<T>& other);
        Matrix<T> operator*(const Matrix<T>& other);
        Matrix<T>& operator=(const Matrix<T>& other);
    
//        Operator overloading for matrix and scalar value
        Matrix<T> operator+(const T& value);
        Matrix<T> operator-(const T& value);
        Matrix<T> operator*(const T& value);
        Matrix<T> operator/(const T& value);
        
};

template<typename T>
class NegMatrix: public Matrix<T>{
    
    public:
    
//        Default constructor
        NegMatrix(){};
//        Parameter constructor
        NegMatrix(int _rows, int _cols): Matrix<T>(_rows, _cols){ };
//        Copy constructor
        NegMatrix(const Matrix<T> &other): Matrix<T>(other){ };
//        Destructor
        ~NegMatrix(){};
    
//        Method
        int accessItem(int i, int j);

};
#endif /* matrix_hpp */

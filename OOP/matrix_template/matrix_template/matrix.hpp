//
//  matrix.hpp
//  matrix_template
//
//  Created by Nastya Bekesheva on 22.02.2022.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <vector>
using namespace std;

//        Parent class
template<typename T>
class Matrix{
    protected:
    
        unsigned int _rows;
        unsigned int _cols;
        vector<vector<T>> _matrix;
    
    public:
//        Constructor/Destructor
        
        Matrix();
        Matrix(int _rows, int _cols);
        Matrix(const Matrix<T> &other);
        ~Matrix() = default;
    
//        Custom methods
        virtual void fill();
        void pushData();
        void getData();
        void getSize();
        void getElement(unsigned int value);
        const int row();
        const int col();
    
//        Operator overloading methods for two matricies
        Matrix<T> operator+(const Matrix<T>& other);
        Matrix<T> operator-(const Matrix<T>& other);
        Matrix<T> operator*(const Matrix<T>& other);
        Matrix<T>& operator=(const Matrix<T>& other);
    
//        Operator overloading for access
        vector<T>& operator [](unsigned i);
        T& operator()(const unsigned int& i, const unsigned int& j);
        const T& operator()(const unsigned int& i, const unsigned int& j) const;
    
//        Operator overloading for matrix and scalar value
        Matrix<T> operator+(const T& value);
        Matrix<T> operator-(const T& value);
        Matrix<T> operator*(const T& value);
        Matrix<T> operator/(const T& value);
    
//        Stream overloading
        template<typename U>
        friend ostream & operator << (ostream &out, const Matrix<U> &matrix);
        template<typename U>
        friend istream & operator >> (istream &in,  Matrix<T> &matrix);
    
};
template<typename U>
extern ostream& operator<<(ostream& out, const Matrix<U> &matrix);

template<typename T>
extern istream & operator >> (istream &in,  Matrix<T> &matrix);
//        Child class
template<typename T>
class NegMatrix: public Matrix<T>{
    
    public:
    
//        Constructor
        NegMatrix(int _rows, int _cols): Matrix<T>(_rows, _cols){ };
        NegMatrix(const Matrix<T> &other): Matrix<T>(other){
            this->_rows = other._rows;
            this->_cols = other._cols;
            this->_matrix = other._matrix;};
        ~NegMatrix() = default;
    
//        Method
        int accessItem(int i, int j);

};

#endif /* matrix_hpp */

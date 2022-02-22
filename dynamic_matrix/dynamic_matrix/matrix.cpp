//
//  matrix.cpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 22.02.2022.
//

#include <iostream>
#include <vector>
#include "matrix.hpp"
using namespace std;

template<typename T>
Matrix<T>::Matrix(){}

template<typename T>
Matrix<T>::Matrix(int _rows, int _cols){
    this->_rows = _rows;
    this->_cols = _cols;
    
    _matrix = new T*[_rows];
    for(int i = 0; i < _rows; i++){
        _matrix[i] = new T[_cols];
        
    }

    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            _matrix[i][j] = 0;
        }        
    }
}

template<typename T>
Matrix<T>::~Matrix<T>(){
    if(_matrix){
        for(int i = 0; i < _rows; i++){
            delete[] _matrix[i];

        }
        delete[] _matrix;
    }
    cout << "Object has been deleted" << endl;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other){
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_matrix = other._matrix;
    
    _matrix = new T*[_rows];
    for(int i = 0; i < _rows; i++){
        _matrix[i] = new T[_cols];
        for(int j = 0; j < _cols; j++){
            _matrix[i][j] = other(i, j);
        }
    }
}

template<typename T>
const int Matrix<T>::row(){
    return this->_rows;
}

template<typename T>
const int Matrix<T>::col(){
    return this->_cols;
}

template<typename T>
void Matrix<T>::getSize(){
    int size = _rows * _cols;
    cout << "Size of your matrix: " << size << endl;
}

template<typename T>
void Matrix<T>::getElement(unsigned int value){
    bool temp = false;
    for(auto i = 0; i < _rows; i++){
        for(auto j = 0; j < _cols; j++){
            if(_matrix[i][j] == value){
                cout << "Element " << value << " found at row: " << i << " col: " << j << endl;
                temp = true;
            }
        }
    }
    if(temp == false){
        cout << "No such element" << endl;
    }
}

template<typename T>
ostream & operator << (ostream &out, const Matrix<T> &matrix){
    for(auto i = 0; i < matrix._rows; i++){
        for(auto j = 0; j < matrix._cols; j++){
            out << matrix._matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

template<typename T>
istream & operator >> (istream &in,  Matrix<T> &matrix){
    for(auto i = 0; i < matrix.row(); i++){
        for(auto j = 0; j < matrix.col(); j++){
            in >> matrix(i, j);
        }
    }
    return in;
}

template<typename T>
T& Matrix<T>::operator()(const unsigned int& i, const unsigned int& j) {
    return _matrix[i][j];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned int& i, const unsigned int& j) const {
    return _matrix[i][j];
}
template<typename T>
T& Matrix<T>::operator [](unsigned i){
    return _matrix[i];
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> & other){
    
    if(this == &other){
            return *this;
        }
    else{
        if(_rows != other._rows || _cols != other._cols){
            this->~Matrix(); _rows = other._rows; _cols = other._cols;
            _matrix = new T* [ _rows ];
                
            for (int i = 0; i < _rows; i++){
                _matrix[i] = new T[ _cols ];
            }
        }
    }
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            _matrix[i][j] = other._matrix[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & other){

    Matrix<T> result(_rows, _cols);
    if(this->_rows == other._rows && this->_cols == other._cols){
        for(auto i = 0; i < _rows; i++){
            for(auto j = 0; j < _cols; j++){

                result(i, j) = _matrix[i][j] + other(i, j);
            }
        }
        return result;
    }
    else{
        cout << "Error" << endl;
    }
    return Matrix<T> ();
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & other){

    Matrix<T> result(_rows, _cols);
    if(this->_rows == other._rows && this->_cols == other._cols){
        for(auto i = 0; i < _rows; i++){
            for(auto j = 0; j < _cols; j++){

                result(i, j) = _matrix[i][j] - other(i, j);
            }
        }
        return result;
    }
    else{
        cout << "Error" << endl;
    }
    return Matrix<T> ();
}


template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & other){
    
    Matrix<T> result(_rows, _cols);
    if(this->_rows == other._rows && this->_cols == other._cols){
        for(auto i = 0; i < _rows; i++){
            for(auto j = 0; j < _cols; j++){
                for(auto k = 0; k < _cols; k++){
                    result(i, j) = result(i, j) + _matrix[i][k] * other(k, j);
                }
            }
        }
        return result;
    }
    else{
        cout << "Error" << endl;
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& value){
    Matrix<T> result(_rows, _cols);
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            result(i, j) = _matrix[i][j] + value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& value){
    Matrix<T> result(_rows, _cols);
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            result(i, j) = _matrix[i][j] - value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& value){
    Matrix<T> result(_rows, _cols);
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            result(i, j) = _matrix[i][j] * value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& value){
    Matrix<T> result(_rows, _cols);
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            result(i, j) = _matrix[i][j] / value;
        }
    }
    return result;
}


template<typename T>
int NegMatrix<T>::accessItem(int i, int j){
    if (abs(i) <= this->_rows && abs(j) <= this->_cols){
        return this->_matrix[this->_rows + i][this->_cols + j];
    }
    else{
        cout << "Incorrect index set";
        return 0;
    }
}




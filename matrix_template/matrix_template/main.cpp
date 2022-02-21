//
//  main.cpp
//  matrix_template
//
//  Created by Nastya Bekesheva on 21.02.2022.
//

#include <iostream>
#include<vector>
using namespace std;

template<typename T>
class Matrix{
    protected:
    
        unsigned int _rows;
        unsigned int _cols;
        vector<vector<T>> _matrix;
    
    public:
//        Constructor/Destructor
    
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
//        Operator overloading methods
        Matrix<T> operator+(const Matrix<T>& other);
        Matrix<T> operator-(const Matrix<T>& other);
        Matrix<T> operator*(const Matrix<T>& other);
        Matrix<T>& operator=(const Matrix<T>& other);
        vector<T>& operator [](unsigned i);
        T& operator()(const unsigned int& i, const unsigned int& j);
        const T& operator()(const unsigned int& i, const unsigned int& j) const;
    
        template<typename U>
        friend ostream & operator << (ostream &out, const Matrix<U> &matrix);
        template<typename U>
        friend istream & operator >> (istream &in,  Matrix<T> &matrix);
    
    
};

template<typename T>
Matrix<T>::Matrix(int _rows, int _cols){
    this->_rows = _rows;
    this->_cols = _cols;
    fill();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other){
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_matrix = other._matrix;
}

template<typename T>
void Matrix<T>::fill(){
    for(auto i = 0; i < _rows; i++){
        vector<T> row;
        for(auto j = 0; j < _cols; j++){
            row.push_back(0);
        }
        _matrix.push_back(row);
    }
}

template<typename T>
void Matrix<T>::pushData(){
    cout << "Enter values: " << endl;
    for(auto i = 0; i < _rows; i++){
        vector<T> row;
        for(auto j = 0; j < _cols; j++){
            cin >>_matrix[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::getData(){
    cout << "Your matrix" << endl;
    for(auto i = 0; i < _rows; i++){
        for(auto j = 0; j < _cols; j++){
            cout << _matrix[i][j] << " ";
        }
        cout << endl;
    }
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
const int Matrix<T>::row(){
    return this->_rows;
}

template<typename T>
const int Matrix<T>::col(){
    return this->_cols;
}

template<typename T>
vector<T>& Matrix<T>::operator [](unsigned i){
    return _matrix[i];
}

template<typename T>
T& Matrix<T>::operator()(const unsigned int& i, const unsigned int& j) {
    return this->_matrix[i][j];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned int& i, const unsigned int& j) const {
    return this->_matrix[i][j];
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> & other){
    
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_matrix = other._matrix;
        
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & other){

    Matrix<T> result(this->_rows, this->_cols);
    if(this->_rows == other._rows && this->_cols == other._cols){
        for(auto i = 0; i < this->_rows; i++){
            for(auto j = 0; j < _cols; j++){

                result(i, j) = this->_matrix[i][j] + other(i, j);
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & other){
    
    Matrix<T> result(this->_rows, this->_cols);
    if(this->_rows == other._rows && this->_cols == other._cols){
        for(auto i = 0; i < this->_rows; i++){
            for(auto j = 0; j < this->_cols; j++){

                result(i, j) = this->_matrix[i][j] - other(i, j);
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & other){
    
    Matrix<T> result(this->_rows, this->_cols);
    if(this->_rows == other._rows && this->_cols == other._cols){
        for(auto i = 0; i < this->_rows; i++){
            for(auto j = 0; j < this->_cols; j++){
                for(auto k = 0; k < this->_cols; k++){
                    result(i, j) = result(i, j) + this->_matrix[i][k] * other(k, j);
                }
            }
        }
    }
    return result;
}

template<typename T>
ostream & operator << (ostream &out, const Matrix<T> &matrix){
    for(auto i = 0; i < matrix._rows; i++){
        for(auto j = 0; j < matrix._cols; j++){
            out << matrix(i, j) << " ";
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

int main() {
    
    Matrix<int> matrix(3, 3);
    cout << "Enter values:" << endl;
    cin >> matrix;
    cout << endl;
    matrix.getData();
    cout << endl;
    matrix.getSize();
    cout << endl;
    matrix.getElement(3);
    cout << endl;
    Matrix<int> mat(3, 3);
    mat.pushData();
    cout << "Adding two matrices" << endl << mat + matrix << endl;
    cout << "Substracting two matrices" << endl << mat - matrix << endl;
    cout << "Multiplying two matrices" << endl << mat*matrix << endl;
    return 0;
}

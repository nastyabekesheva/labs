//
//  main.cpp
//  matrix
//
//  Created by Nastya Bekesheva on 19.02.2022.
//

#include <iostream>
#include <vector>
using namespace std;

class Matrix{
    protected:
    
        unsigned int _rows;
        unsigned int _cols;
        vector<vector<unsigned int> > _matrix;
    
    public:
    
        Matrix(int _rows, int _cols);
        Matrix(const Matrix &other);
        ~Matrix() = default;

    
        virtual void pushData();
        void getData();
        void getSize();
        void getElement(unsigned int value);
    
        Matrix& operator=(const Matrix &other);
        vector<unsigned int>& operator [](unsigned i);
    
        friend ostream & operator << (ostream &out, const Matrix &matrix);
        friend istream & operator >> (istream &in,  Matrix &matrix);
    
    
};

class NegMatrix: public Matrix{
    
    public:
    
        NegMatrix(int _rows, int _cols): Matrix(_rows, _cols){
            this->_rows = _rows;
            this->_cols = _cols;
        };
        int accessItem(int i, int j);

    
    
};

Matrix::Matrix(int _rows, int _cols){
    this->_rows = _rows;
    this->_cols = _cols;
    pushData();
}

Matrix::Matrix(const Matrix& other){
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_matrix = other._matrix;
}

void Matrix::pushData(){
    cout << "Enter values: " << endl;
    for(auto i = 0; i < _rows; i++){
        vector<unsigned int> row;
        for(auto j = 0; j < _cols; j++){
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        _matrix.push_back(row);
    }
}

void Matrix::getData(){
    cout << "Your matrix" << endl;
    for(auto i = 0; i < _rows; i++){
        for(auto j = 0; j < _cols; j++){
            cout << _matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::getSize(){
    int size = _rows * _cols;
    cout << "Size of your matrix: " << size << endl;
}

void Matrix::getElement(unsigned int value){
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

Matrix& Matrix::operator=(const Matrix &other){
    
    this->_rows = other._rows;
    this->_cols = other._cols;
    this->_matrix = other._matrix;
        
    return *this;
}

vector<unsigned int>& Matrix::operator [](unsigned i){
    return _matrix[i];
}

ostream & operator << (ostream &out, const Matrix &matrix){
    for(auto i = 0; i < matrix._rows; i++){
        for(auto j = 0; j < matrix._cols; j++){
            out << matrix._matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
 
istream & operator >> (istream &in,  Matrix &matrix){
    for(auto i = 0; i < matrix._rows; i++){
        for(auto j = 0; j < matrix._cols; j++){
            in >> matrix._matrix[i][j];
        }
    }
    return in;
}

int NegMatrix::accessItem(int i, int j){
    if (abs(i) <= _rows && abs(j) <= _cols){
        return _matrix[_rows + i][_cols + j];
    }
    else{
        cout << "Incorrect index set";
        return 0;
    }
}

int main() {
    Matrix matrix(3, 3);
    cout << endl;
    matrix.getData();
    cout << endl;
    matrix.getSize();
    cout << endl;
    matrix.getElement(3);
    cout << endl;
    NegMatrix mat(3, 3);
    int value = mat.accessItem(-1, -2);
    cout << value << endl;
    cout << "Setting data with cin >>" << endl;
    cin >> mat;
    cout << "Getting data with cout <<" << endl;
    cout << mat;
    return 0;
}

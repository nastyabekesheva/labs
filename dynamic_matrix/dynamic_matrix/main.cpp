//
//  main.cpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 22.02.2022.
//

#include <iostream>
#include "matrix.hpp"
#include "matrix.cpp"
#include "complex.hpp"
#include "complex.cpp"

int main() {
    Matrix<int> matrix(3, 3);
    cout << "Enter value:" << endl;
    cin >> matrix;
    cout << "Your matrix:" << endl;
    cout << matrix;
    matrix.getSize();
    cout << endl;
    matrix.getElement(3);
    cout << endl;
    Matrix<int> mat(matrix);
    Matrix<int> n = mat + matrix;
    cout << "Adding two matrices" << endl <<  n << endl;
    cout << "Substracting two matrices" << endl << mat - matrix << endl;
    cout << "Multiplying two matrices" << endl << mat * matrix << endl;
    cout << "Adding value to matrix" << endl << matrix + 2 << endl;
    cout << "Substracting value from matrix" << endl << matrix - 2 << endl;
    cout << "Multiplying matrix by value" << endl << matrix * 2 << endl;
    cout << "Dividing matrix by value" << endl << matrix / 2 << endl;
    NegMatrix<int> m(mat);
    cout << "Accessing element by negative index" << endl;
    cout << m.accessItem(-1, -1) << endl;

    Complex c0(1, 2);
    Complex c1(1, 1);
    Complex c2(1, 5);
    Complex c3(3, 5);
    
    Matrix<Complex> comp(2, 2);
    comp(0, 0) = c0;
    comp(0, 1) = c1;
    comp(1, 0) = c2;
    comp(1, 1) = c3;

    cout << comp;
    
    
    return 0;
}

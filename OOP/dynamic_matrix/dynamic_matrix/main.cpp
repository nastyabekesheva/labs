//
//  main.cpp
//  dynamic_matrix
//
//  Created by Nastya Bekesheva on 22.02.2022.
//

/*  Matrix Template Class with dynamic memory for Lab 5  */

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


    Matrix<Complex> comp(2, 2);
    cin >> comp;
    cout << comp;
    
    Complex a(1, 20);
    Complex b(3, 10);
    
    a + b;
    
    return 0;
}

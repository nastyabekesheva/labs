//
//  main.cpp
//  matrix_template
//
//  Created by Nastya Bekesheva on 21.02.2022.
//

#include <iostream>
#include <vector>
#include "matrix.hpp"
#include "matrix.cpp"
using namespace std;




int main() {
    
    Matrix<int> matrix(3, 3);
    cout << "Enter values:" << endl;
    cin >> matrix;
    cout << endl;
    cout << matrix;
    cout << endl;
    matrix.getSize();
    cout << endl;
    matrix.getElement(3);
    cout << endl;
    Matrix<int> mat(3, 3);
    NegMatrix<int> n(2, 2);
    cin >> n;
    cout << "Accessing element by negative index" << endl;
    cout << n.accessItem(-1, -1);
    cin >> mat;
    cout << "Adding two matrices" << endl << mat + matrix << endl;
    cout << "Substracting two matrices" << endl << mat - matrix << endl;
    cout << "Multiplying two matrices" << endl << mat * matrix << endl;
    cout << "Adding value to matrix" << endl << matrix + 2 << endl;
    cout << "Substracting value from matrix" << endl << matrix - 2 << endl;
    cout << "Multiplying matrix by value" << endl << matrix * 2 << endl;
    cout << "Dividing matrix by value" << endl << matrix / 2 << endl;
    return 0;
}

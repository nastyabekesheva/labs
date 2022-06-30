//
//  main.cpp
//  Complex
//
//  Created by Nastya Bekesheva on 03.05.2022.
//

#include <iostream>
#include <string>
#include <cmath>
#include "Complex.hpp"

int main() {
    
    complex<int> ct(8, 7);
    complex<double> c(8.5, 3.93);
    std::cout << c;
//    std::cout << (ct >= 8) << std::endl;
    Real<int> r(5);
    Real<int> g(6);
    Real<int> h = r+g;
    std::cout << h;
    
    Real<int> j = r+ct;
    std::cout << j;
    
    return 0;
}

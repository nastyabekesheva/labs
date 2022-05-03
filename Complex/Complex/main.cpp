//
//  main.cpp
//  Complex
//
//  Created by Nastya Bekesheva on 03.05.2022.
//

#include <iostream>
#include <string>
#include "Complex.hpp"

int main(int argc, const char * argv[]) {
    
    complex<int> ct(8, 3);
    complex<double> c(1.9, 2.8);
    c -= 5;
    std::cin >> c;
    std::cout << c;
    
    std::cout << c.real() << " " << c.imag() << std::endl;
    
    return 0;
}

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

int main(int argc, const char * argv[]) {
    
    complex<int> ct(8, 7);
    complex<double> c(8.5, 3.93);
    std::cout << c;
    std::cout << (ct >= 8) << std::endl;
    
    return 0;
}

//
//  GCD.cpp
//  lab_1
//
//  Created by Nastya Bekesheva on 07.02.2023.
//

#include <stdio.h>

int GCD(int a, int b){
    if (a < b)  std::swap(a, b); // 'a' must be greater than 'b'
    if (b == 0)  return a; // gcd of 'a' and 0 is always 'a'
    int r = a % b; // remainder
    return GCD(b, r);
}

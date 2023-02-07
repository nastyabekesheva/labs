//
//  TowersOfHanoi.cpp
//  lab_1
//
//  Created by Nastya Bekesheva on 07.02.2023.
//
#include <stdio.h>

void TowersOfHanoi(char start, char help, char end, int n){
    if (n > 0) { // number of disks cannot be less than 0
        TowersOfHanoi(start, end, help, n-1); // move disk from start point to help point
        std::cout << "Disk " << n << " : " << start << " -> " << end << std::endl;
        TowersOfHanoi(help, start, end, n-1); // move disk from help point to end point
    }
}


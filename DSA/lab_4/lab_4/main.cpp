//
//  main.cpp
//  lab_4
//
//  Created by Nastya Bekesheva on 28.03.2023.
//

#include <iostream>
#include "Queue.cpp"

int main(int argc, const char * argv[]) {
    Queue<int> q;
    int d = q.deQueue();
    std::cin >> q;
    std::cout << q;
    int x = q.deQueue();
    std::cout << q;
    std::cout << "Hello, World!\n";
    return 0;
}

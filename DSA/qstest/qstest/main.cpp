//
//  main.cpp
//  qstest
//
//  Created by Nastya Bekesheva on 30.03.2023.
//

#include <iostream>
#include <queue>
#include <stack>

int main(int argc, const char * argv[]) {
    std::queue<int> stdq;

    stdq.push(1);
    stdq.push(2);
    stdq.push(3);

    while (!stdq.empty())
    {
        std::cout << stdq.front() << " ";
        stdq.pop();
    }
    
    std::cout << std::endl;

    std::stack<int> stds;
    stds.push(1);
    stds.push(2);
    stds.push(3);
        
    while (!stds.empty())
    {
        std::cout << stds.top() <<" ";
        stds.pop();
    }
    
    std::cout << std::endl;
    
    return 0;
}

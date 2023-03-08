//
//  main.cpp
//  lab_3
//
//  Created by Nastya Bekesheva on 07.03.2023.
//

#include <iostream>
#include <string>
#include "LinkedList.cpp"

int main(int argc, const char * argv[]) {
    LinkedList<std::string> lst;
//    lst.append(1);
//    lst.append(2);
//    lst.append(3);
//    lst.append(4);
//    lst.print();
//    std::string tmp;
    std::cin >> lst;
    std::cout << lst;
    return 0;
}

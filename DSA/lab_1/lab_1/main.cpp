//
//  main.cpp
//  lab_1
//
//  Created by Nastya Bekesheva on 07.02.2023.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "TowersOfHanoi.cpp"
#include "GCD.cpp"

bool isNumber(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    bool action = true;
    while (action) {
        std::cout << "Enter key to procede:\n 1. Calculate GCD\n 2. Towers of Hanoi\n 3. Exit\n";
        std::string key;
        std::cin >> key;
        if (isNumber(key) == true) {
            int newKey = stoi(key);
            switch (newKey) {
                case 1: {
                    std::cout << "Calculating GCD...\nEnter 'a' and 'b' separated by whitespace or enter:\n";
                    std::string a, b;
                    std::cin >> a >> b;
                    
                    if (isNumber(a) == true && isNumber(b) == true) {
                        std::cout << "GCD(" << a << ", " << b << ") = " << GCD(stoi(a), stoi(b)) << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Invalid input" << std::endl;
                        break;
                    }
                }
                case 2: {
                    std::cout << "Geterating Towers of Hanoi...\nEnter number of disks:\n";
                    std::string n;
                    std::cin >> n;
                    if (isNumber(n) == true){
                        if (stoi(n) > 0){
                            TowersOfHanoi T(stoi(n));
                            T.start();
                            std::cout << "Steps taken: " << steps << std::endl;
                            break;
                        }
                        else {
                            std::cout << "Invalid input" << std::endl;
                            break;
                        }
                        
                    }
                    else {
                        std::cout << "Invalid input" << std::endl;
                        break;
                    }
                }
                case 3: {
                    action = false;
                    std::cout << "Bye!" << std::endl;
                    break;
                }
                default:
                    break;
            }
        }
        else { std::cout << "Invalid input" << std::endl; }
    }

    return 0;
}

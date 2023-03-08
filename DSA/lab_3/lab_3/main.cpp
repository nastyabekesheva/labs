//
//  main.cpp
//  lab_3
//
//  Created by Nastya Bekesheva on 07.03.2023.
//

#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
#include "DataProcessing.cpp"

int main(int argc, const char * argv[]) {
    std::cout << "Enter maximum amount of words in text:" << std::endl;
    unsigned int size;
    std::cin >> size;
    LinkedList<std::string> lst;
    lst.set_max_size(size);
    std::cout << std::endl << "Enter text. Enter /~ to stop." << std::endl;
    std::cin >> lst;
    auto start_dll = std::chrono::high_resolution_clock::now();
    process_list(lst);
    auto stop_dll = std::chrono::high_resolution_clock::now();
    auto duration_dll = duration_cast<std::chrono::microseconds>(stop_dll - start_dll);
    std::cout << "Time taken: "
                     << duration_dll.count() << " microseconds" << std::endl;
    std::string* array = new std::string[lst.size()];
    auto start_da = std::chrono::high_resolution_clock::now();
    process_text(array, lst);
    auto stop_da = std::chrono::high_resolution_clock::now();
    auto duration_da = duration_cast<std::chrono::microseconds>(stop_da - start_da);
    std::cout << "Time taken: "
                     << duration_da.count() << " microseconds" << std::endl;
    
    return 0;
}

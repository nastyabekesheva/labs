//
//  main.cpp
//  lab_5
//
//  Created by Nastya Bekesheva on 11.04.2023.
//

#include <iostream>
#include "DataProcessing.cpp"


int main(int argc, const char * argv[]) {

    std::string filename("/Users/nastyabekesheva/Desktop/labs/DSA/lab_5/lab_5/data.txt");
    std::string file_contents;
    file_contents = read_file(filename);
    std::cout << file_contents << std::endl;
    std::vector<std::string> vec_data = string_to_vector(file_contents);
    BinarySearchTree<std::string>* tree = vector_to_tree(vec_data);
    std::cout << *(tree);
    std::cout  << "Amount of words that start with char 'w' in file: " << tree->search_char('w') << std::endl;
    tree->remove_char('w');
    std::cout << *(tree);
    std::cout << *(tree);
//    BinarySearchTree<std::string> BST;
//    std::cin >> BST;
//    std::cout << BST;
    return 0;
}

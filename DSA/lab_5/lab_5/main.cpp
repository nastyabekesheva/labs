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
    std::cout << "Contents of file: " << file_contents << std::endl;
    std::vector<std::string> vec_data = string_to_vector(file_contents);
    BinarySearchTree<std::string>* tree = vector_to_tree(vec_data);
    std::cout << "Height of tree: " << tree->height() << std::endl;
    std::cout << "Inorder walk: ";
    tree->inorder_tree_walk();
    std::cout << std::endl;
    std::cout << *(tree);
    std::cout  << "Amount of words that start with char 'w' in file: " << tree->search_char('w') << std::endl;
    tree->remove_char('w');
    std::cout << *(tree);
    std::cout << *(tree);
    /*
        Binary search trees are much easier to understand when they contain numbers
        so lets use overloaded stream and enter '5 3 2 4 7 6 8'
     */
    BinarySearchTree<int> BST;
    std::cin >> BST;
    std::cout << "Height of tree: " << BST.height() << std::endl;
    std::cout << "Inorder walk: ";
    BST.inorder_tree_walk();
    std::cout << std::endl;
    BST.remove(6);
    std::cout << BST;
    return 0;
}

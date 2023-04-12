//
//  DataProcessing.cpp
//  lab_5
//
//  Created by Nastya Bekesheva on 12.04.2023.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BinarySearchTree.cpp"

std::string read_file(const std::string& path) {
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

std::vector<std::string> string_to_vector(std::string str)
{
    std::istringstream iss(str);
    std::vector<std::string> data;
        
    std::string tmp;
    while (std::getline(iss, tmp, ' '))
    {
        data.push_back(tmp);
    }
    
    return data;
}

BinarySearchTree<std::string>* vector_to_tree(std::vector<std::string> vec)
{
    BinarySearchTree<std::string>* BST = new BinarySearchTree<std::string>();
    for (auto & i : vec)
    {
        BST->insert(i);
    }
    return BST;
}

//int search_tree(BinarySearchTree<std::string>* BST, char ch)
//{
//    std::string
//};



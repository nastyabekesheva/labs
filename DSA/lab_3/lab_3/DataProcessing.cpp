//
//  parser.cpp
//  lab_3
//
//  Created by Nastya Bekesheva on 08.03.2023.
//

#include <stdio.h>
#include <iostream>
#include "LinkedList.cpp"

bool in_alph(std::string str)
{
    std::string alph = "abcdefghijklmnopqrstuvwxyz";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if(strstr(alph.c_str(),str.c_str()))
        {
            return true;
        }
        else{
            return false;
        }
}

void process_list(LinkedList<std::string> & lst){
    std::cout << "\nText after proccesing (stored in linked list):\n [";
    if (lst.head())
    {
        std::string head_data = lst.head()->_data;
        Node<std::string> *node = lst.head();
        while (node != nullptr)
        {
            if (node->_data != head_data && in_alph(node->_data))
            {
                std::string data = node->_data;
                data.pop_back();
                std::cout << data << ". ";
            }
            node = node->_next;
        }
    }
    std::cout << "]" << std::endl;
    
}

void process_text(std::string* array, LinkedList<std::string> & lst)
{
    int size = 0;
    std::string tmp;
    Node<std::string> *node = lst.head();
    while (node != nullptr)
    {
        array[size] = node->_data;
        node = node->_next;
        size++;
    }
    std::cout << "\nText after proccesing (stored in dynamic array):\n [";
    for(int i = 0; i < size; i++)
    {
        if (array[i] != array[0] && in_alph(array[i]))
        {
            array[i].pop_back();
            std::cout << array[i] << ". ";
        }
    }
    std::cout << "]" << std::endl;
}

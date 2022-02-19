//
//  LinkedList.hpp
//  linked_list
//
//  Created by Nastya Bekesheva on 20.12.2021.
//


#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

struct Link{
    string str;
    Link *next;
};

void get_list(Link *head);
void print_list(Link *head);
void return_second(Link *head);
void return_last(Link *head);
void fill(Link *head, string str1);



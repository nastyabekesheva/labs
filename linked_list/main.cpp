//
//  main.cpp
//  linked_list
//
//  Created by Nastya Bekesheva on 20.12.2021.
//

#include <iostream>
#include <string>
#include "LinkedList.hpp"
int main(){
    bool stop = false;
    int choice;
    Link *head = new Link;
    head->next = NULL;
    
    cout << "1. get list from input" << endl
        << "2. print list" << endl
        << "3. print second pointer" << endl
        << "4. print last pointer" << endl
        << "5. fill with given string" << endl
        << "6. stop" << endl;

    while (!stop){
        cout << "Your choice: " << endl;
        cin >> choice;
        switch(choice){
        case 1: get_list(head);
            break;
        case 2: print_list(head);
            break;
        case 3: return_second(head);
            break;
        case 4: return_last(head);
            break;
        case 5: fill(head, "hello");
            break;
        case 6: stop = true;
            break;
        default:
            cout << "The input is invalid";
            stop = true;
        }
    }
    
}

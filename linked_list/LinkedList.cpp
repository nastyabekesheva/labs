//
//  LinkedList.cpp
//  linked_list
//
//  Created by Nastya Bekesheva on 20.12.2021.
//

#include "LinkedList.hpp"
#include <iostream>
#include <string>

void get_list(Link *head){
    
    bool stop = false;
    string buff;
    
    cout << "Enter new elements" << endl << "If you want to stop enter \"-s\"" << endl;

    while (!stop){

        cin >> buff;

        if (buff == "-s"){
            
            stop = true;
            
        }
        else{
            Link *current = head;
            Link *temp = new Link;
            temp->str = buff;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                return;
            }
            while(current->next != NULL){
                current = current->next;
            }
            current->next = temp;
            
        }
    }
    
}

void print_list(Link *head){
  while(head != NULL){
      
      cout << head->str << " ";
      head = head->next;
      
  }
    
    cout << endl;
    
}

void return_second(Link *head){
    Link *ptr = head->next;
    Link *ptr1 = ptr->next;
    
    cout << ptr1 << " - " << ptr1->str <<endl;
    
}

void return_last(Link *head){
    Link *ptr = head;
    Link *ptr1 = ptr->next;
    
    while(ptr1){
        
        if(ptr1->next == NULL){
            
            cout << ptr1 << " - " << ptr1->str << endl;
            break;
            
        }
        
        ptr = ptr1;
        ptr1 = ptr1->next;
    }
}
    
void fill(Link *head, string str1){
    Link *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
        ptr->str = str1;
    }
}

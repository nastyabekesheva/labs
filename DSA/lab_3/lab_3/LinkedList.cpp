//
//  LinkedList.cpp
//  lab_3
//
//  Created by Nastya Bekesheva on 07.03.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>

template<typename T>
struct Node
{
    T _data;
    Node* _next;
    Node* _prev;
    Node(T data): _data(data), _next(nullptr), _prev(nullptr) {}
};

template<typename T>
class LinkedList
{
private:
    Node<T>* _head;
    Node<T>* _tail;
    unsigned int _size;
    unsigned int _max_size;
    
public:
    unsigned int size();
    unsigned int max_size();
    void print();
    LinkedList(): _head(nullptr), _tail(nullptr), _size(0), _max_size(4294967295) {}
    ~LinkedList();
    void insert(T data);
    void append(T data);
    void pop(T data);
    Node<T> *search(T data);
    void set_max_size(unsigned int n);
    template<typename U>
    friend std::ostream & operator << (std::ostream &out, const LinkedList<U> &lst);
    template<typename U>
    friend std::istream & operator >> (std::istream &in,  LinkedList<T> &lst);
    
    
};

template<typename T>
LinkedList<T>::~LinkedList<T>()
{
    Node<T> *tmp = nullptr;
    while (_head)
    {
        tmp = _head;
        _head = _head->_next;
        delete tmp;
    }
    _head = nullptr;
}

template<typename T>
unsigned int LinkedList<T>::size()
{
    return this->_size;
}

template<typename T>
unsigned int LinkedList<T>::max_size()
{
    return this->_max_size;
}

template<typename T>
void LinkedList<T>::set_max_size(unsigned int n)
{
    this->_max_size = n;
}

template<typename T>
void LinkedList<T>::print()
{
    Node<T> *node = _head;
    while (node != nullptr)
    {
        std::cout << node->_data << ' ';
        node = node->_next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::insert(T data)
{
    Node<T> *node = new Node(data);
    //Node<T> *tmp = _head;
    
    if (!_head)
    {
        _head = node;
        _tail = node;
    }
    else
    {
        node->_next = _head;
        _head = node;
        node->_next->_prev = node;
    }
    _size++;
}

template<typename T>
void LinkedList<T>::append(T data)
{
    Node<T> *node = new Node(data);
    if (!_head)
    {
        _head = node;
        _tail = node;
    }
    else if (_tail->_next == nullptr)
    {
        _tail->_next = node;
        _tail = node;
    }
    _size++;
    
}

template<typename T>
std::ostream & operator << (std::ostream &out, const LinkedList<T> &lst)
{
    Node<T> *node = lst._head;
    while (node != nullptr)
    {
        out << node->_data << ' ';
        node = node->_next;
    }
    out << std::endl;
    return out;
}

template<typename T>
std::istream & operator >> (std::istream &in, LinkedList<T> &lst)
{
    std::string tmp;
    while (tmp != "/~" && lst.size() < lst.max_size())
    {
        in >> tmp;
        lst.append(tmp);
        
    }
    lst.pop("/~");
    return in;
}

template<typename T>
Node<T>* LinkedList<T>::search(T data)
{
    Node<T> *node = this->_head;
    while (node != nullptr)
    {
        if (node->_data == data)
        {
            return node;
        }
        node = node->_next;
    }
    return nullptr;
    
}

template<typename T>
void LinkedList<T>::pop(T data)
{
    Node<T>* data_node = search(data);
    Node<T>* tmp = _head;
    
    if (tmp == data_node)
    {
        _head = tmp->_next;
    }
    else if (data_node)
    {
        while (data_node != nullptr)
        {
            if (tmp->_next == data_node)
            {
                tmp->_next = data_node->_next;
                delete data_node;
                return;
            }
            tmp = tmp->_next;
        }
    }
}

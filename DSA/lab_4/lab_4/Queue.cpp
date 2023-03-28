//
//  Queue.cpp
//  lab_4
//
//  Created by Nastya Bekesheva on 28.03.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

template<typename T>
struct Node
{
    T _data;
    Node* _next;
    Node(T data): _data(data), _next(nullptr) {}
    ~Node()
    {
        if (_next)
            delete _next;
    }
};

template<typename T>
class Queue
{
private:
    Node<T>* _front;
    Node<T>* _rear;
    unsigned int _size;
public:
    Queue(): _front(nullptr), _rear(nullptr), _size(0) {}
    ~Queue();
    void enQueue(T data);
    T deQueue();
    T& front() const;
    T& rear() const;
    unsigned int size() const;
    template<typename U>
    friend std::ostream & operator << (std::ostream &out, const Queue<U> &q);
    template<typename U>
    friend std::istream & operator >> (std::istream &in,  Queue<T> &q);
};

template<typename T>
Queue<T>::~Queue()
{
    if (_front)
        delete _front; //    cleaning memory
}

template<typename T>
void Queue<T>::enQueue(T data)
{
    Node<T>* tmp = new Node(data);
    
    if (!_rear) //    if queue is empty
    {
        _front = _rear = tmp; //    new node is both front and rear
        _size++;
        return;
    }
    
    _rear->_next = tmp; //    add tmp to queue
    _rear = tmp; //    move rear
    _size++;
}

template<typename T>
T Queue<T>::deQueue()
{
    if (!_front)
        return -1; //    if queue is empty there's nothing to delete
    
    Node<T>* tmp = _front;
    _front = _front->_next; //    move front
    _size--;
    
    if (!_front)
        _rear = nullptr; //    if there's no front there's no rear
    
    T data = tmp->_data; //    store data
    tmp->_next = nullptr; //    unlink nodes
    delete tmp;
    
    return data;
}

template<typename T>
T& Queue<T>::front() const
{
    return *(_front->_data);
}

template<typename T>
T& Queue<T>::rear() const
{
    return *(_rear->_data);
}

template<typename T>
unsigned int Queue<T>::size() const
{
    return _size;
}

template<typename T>
std::ostream & operator << (std::ostream &out, const Queue<T> &q)
{
    Node<T> *node = q._front;
    while (node) //    iterate through queue
    {
        out << node->_data << ' '; //    print data
        node = node->_next;
    }
    out << std::endl;
    return out;
}

template<typename T>
std::istream & operator >> (std::istream &in, Queue<T> &q)
{
    std::cout << "Enter size of queue:" << std::endl;
    std::string size; //    initialize max size
    in >> size;
    std::istringstream iss(size);
    int size_;
    iss >> std::noskipws >> size_;
    std::string tmp; //    tmp string for data
    std::cout << "Enter queue:" << std::endl;
    while (q.size() < size_)
    {
        in >> tmp;
        std::istringstream iss(tmp);
        T f;
        iss >> std::noskipws >> f;
        q.enQueue(f); //    add data to queue
    }
    return in;
}

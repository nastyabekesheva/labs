//
//  CircularQueue.cpp
//  lab_4
//
//  Created by Nastya Bekesheva on 28.03.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

template<typename T>
class CircularQueue
{
private:
    T* _front;
    T* _rear;
    unsigned int _size;
    unsigned int _max_size;
    T* _data;
    
public:
    CircularQueue(unsigned int size);
    ~CircularQueue();
    void enQueue(T data);
    T deQueue();
    T& front() const;
    T& rear() const;
    unsigned int size() const;
    unsigned int max_size() const;
    template<typename U>
    friend std::ostream & operator << (std::ostream &out, const CircularQueue<U> &q);
    template<typename U>
    friend std::istream & operator >> (std::istream &in,  CircularQueue<T> &q);
};

template<typename T>
T& CircularQueue<T>::front() const
{
    return *(_front);
}

template<typename T>
T& CircularQueue<T>::rear() const
{
    return *(_rear);
}

template<typename T>
unsigned int CircularQueue<T>::size() const
{
    return _size;
}

template<typename T>
unsigned int CircularQueue<T>::max_size() const
{
    return _max_size;
}

template<typename T>
CircularQueue<T>::CircularQueue(unsigned int size)
{
    _max_size = size;
    _size = 0;
    _data = new T[_size]; //    allocate array
    _front = _rear = nullptr;
}

template<typename T>
CircularQueue<T>::~CircularQueue()
{
    if(_data)
        delete[] _data; //    cleaning memory
}

template<typename T>
void CircularQueue<T>::enQueue(T data){
    if (_size == 0)
    {
        _front = _rear = _data; //    only one element in queue
        *(_data) = data; //    assign data
        _size++;
        return;
    }

    if (_size == _max_size)
    {
        if(_front == _data + _max_size - 1) //    circular front++
            _front = _data;
        else
             _front++;
        _size--;
        std::cout << "Max size reached" << std::endl;
    }

    if (_rear == _data + _max_size -1) //    if we are at an end of queue
    {
        _rear = _data;
    }
    else
        if(_rear == _data + _max_size - 1) //    circular front++
            _rear = _data;
        else
             _rear++;; //    just go to next cell

    *(_rear) = data; //    assign data
    _size++;
    
}

template<typename T>
T CircularQueue<T>::deQueue()
{
    if (_size == 0)
        return -1; //    if queue is empty there's nothing to delete
    
    T data = *(_front); //    store data
    
    if(_front == _data + _max_size -1) //    if we are at an end of queue
        _front = _data;
    else
    {
        _front++; //    just move front
    }
        
    
    _size--;
    return data;
}

template<typename T>
std::ostream & operator << (std::ostream &out, const CircularQueue<T> &q)
{
    std::string tmp;
    out << std::endl << "\n\u250c\u2500[ ";
    
    auto front = q._front;
    auto rear = q._rear;
    if(rear == q._data + q._max_size - 1) //    circular rear++
          rear = q._data;
    else
         rear++;
    
    do
    {
        out << *(front) << ' ';
        std::stringstream ss;
        ss << *(front);
        std::string s = ss.str(); //    visualization magic
        int n = s.length();
        std::string space(n, ' ');
        tmp += space;
        tmp += ' ';
        if(front == q._data + q._max_size - 1) //    circular front++
              front = q._data;
        else
             front++;
    }
    while(front != rear);  //    iterate through queue

    out << "]\u2500\u2510\n" << "\u2515\u2500\u2500" << tmp << "\u2190\u2500\u2500\u2518\n";
    return out;
}
    
template<typename T>
std::istream & operator >> (std::istream &in,  CircularQueue<T> &q)
{
    std::cout << "Max size: " << q.max_size() << std::endl;
    std::string tmp; //    tmp string for data
    std::cout << "Enter queue:" << std::endl;
    while(q.size() < q.max_size())
    {
        in >> tmp;
        std::istringstream iss(tmp);
        T f;
        iss >> std::noskipws >> f;
        q.enQueue(f); //    add data to queue
    }
    
    return in;
}

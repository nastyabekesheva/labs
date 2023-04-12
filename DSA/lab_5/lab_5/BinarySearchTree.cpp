//
//  BinarySearchTree.cpp
//  lab_5
//
//  Created by Nastya Bekesheva on 11.04.2023.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<typename T>
struct Node
{
    T* _data;
    Node* _parent;
    Node* _left;
    Node* _right;
    Node(T data): _data(new T(data)), _parent(nullptr), _left(nullptr), _right(nullptr) {}
    Node(T data, Node<T>* p): _data(new T(data)), _parent(p), _left(nullptr), _right(nullptr) {}
    ~Node()
    {
        if (_data)
            delete _data;
        if (_left)
            delete _left;
        if (_right)
            delete _right;
    }
};

template<typename T>
class BinarySearchTree
{
private:
    Node<T>* _root;
//    unsigned int _size;
public:
    BinarySearchTree(): _root(nullptr) {}
//    ~BinarySearchTree<T>();
    void insert(T data);
    void insert(Node<T>* root, T data);
    void inorder_tree_walk();
    void inorder_tree_walk(Node<T>* node);
    Node<T>* search(T data);
    Node<T>* search(Node<T>* node, T data);
    Node<T>* min();
    Node<T>* min(Node<T>* node);
    Node<T>* max();
    Node<T>* max(Node<T>* node);
    Node<T>* successor(T data);
    Node<T>* successor(Node<T>* node);
    Node<T>* predecessor(T data);
    Node<T>* predecessor(Node<T>* node);
    void remove(T data);
    void remove(Node<T>* node);
    int height();
    int height(Node<T>* node);
    void display();
    void display(Node<T>* node);
    void display(std::string str, Node<T>* node, bool is_left);
//    template<typename U>
//    friend std::ostream & operator << (std::ostream &out, const BinarySearchTree<U> &tree);
//    template<typename U>
//    friend std::istream & operator >> (std::istream &in,  BinarySearchTree<T> &tree);
    int search_char(char data);
    int search_char(Node<T>* node, char data);
    void remove_char(char data);
    void remove_char(Node<T>* node, char data);
};

template<typename T>
void BinarySearchTree<T>::inorder_tree_walk()
{
    return inorder_tree_walk(_root);
}

template<typename T>
void BinarySearchTree<T>::inorder_tree_walk(Node<T>* node)
{
    if (node)
    {
        inorder_tree_walk(node->_left);
        std::cout << *(node->_data) << " ";
        inorder_tree_walk(node->_right);
    }
}

template<typename T>
void BinarySearchTree<T>::insert(T data)
{
    if (!_root)
    {
        _root = new Node<T>(data);
    }
    else
    {
        insert(_root, data);
    }
}

template<typename T>
void BinarySearchTree<T>::insert(Node<T>* node, T data)
{
    if (data > *(node->_data))
    {
        if (!node->_right)
        {
            node->_right = new Node<T>(data, node);
        }
        else
        {
            insert(node->_right, data);
        }
    }
    else if (data < *(node->_data))
    {
        if (!node->_left)
        {
            node->_left = new Node<T>(data, node);
        }
        else
        {
            insert(node->_left, data);
        }
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::search(T data)
{
    return search(_root, data);
}

template<typename T>
Node<T>* BinarySearchTree<T>::search(Node<T>* node, T data)
{
    while (node && data != *(node->_data))
    {
        if (data < *(node->_data))
        {
            node = node->_left;
        }
        else
        {
            node = node->_right;
        }
    }
    return node;
}

template<typename T>
Node<T>* BinarySearchTree<T>::min()
{
    return min(_root);
}

template<typename T>
Node<T>* BinarySearchTree<T>::min(Node<T>* node)
{
    if(!node)
    {
        node = _root;
    }
    while (node->_left)
    {
        node = node->_left;
    }
    return node;
}

template<typename T>
Node<T>* BinarySearchTree<T>::max()
{
    return max(_root);
}

template<typename T>
Node<T>* BinarySearchTree<T>::max(Node<T>* node)
{
    while (node->_right)
    {
        node = node->_right;
    }
    return node;
}

template<typename T>
Node<T>* BinarySearchTree<T>::successor(T data)
{
    return successor(search(data));
}

template<typename T>
Node<T>* BinarySearchTree<T>::successor(Node<T>* node)
{
    if (node->_right)
    {
        return min(node->_right);
    }
    Node<T>* tmp = node->_parent;
    while (tmp && node == tmp->_right)
    {
        node = tmp;
        tmp = tmp->_parent;
    }
    return tmp;
}

template<typename T>
Node<T>* BinarySearchTree<T>::predecessor(T data)
{
    return successor(search(data));
}

template<typename T>
Node<T>* BinarySearchTree<T>::predecessor(Node<T>* node)
{
    if (node->_left)
    {
        return min(node->_rigth);
    }
    Node<T>* tmp = node->_parent;
    while (tmp && node == tmp->_left)
    {
        node = tmp;
        tmp = tmp->_parent;
    }
    return tmp;
}

template<typename T>
void BinarySearchTree<T>::remove(T data)
{
    remove(search(data));
}

template<typename T>
void BinarySearchTree<T>::remove(Node<T>* node)
{
    Node<T>* tmp1;
    Node<T>* tmp2;
    if (_root)
    {
        if (!node->_left || !node->_right)
        {
            tmp1 = node;
        }
        else
        {
            tmp1 = successor(node);
        }
        
        if (tmp1->_left)
        {
            tmp2 = tmp1->_left;
        }
        else
        {
            tmp2 = tmp1->_right;
        }
        if (tmp2)
        {
            tmp2->_parent = tmp1->_parent;
        }
        if (!tmp1->_parent)
        {
            _root = tmp2;
        }
        else if (tmp1 == tmp1->_parent->_left)
        {
            tmp1->_parent->_left = tmp2;
        }
        else
        {
            tmp1->_parent->_right = tmp2;
        }
        if (tmp1 != node)
        {
            T* tmp_data = node->_data;
            node->_data = tmp1->_data;
            delete tmp_data;
            tmp1->_data = nullptr;
        }
        tmp1->_right = tmp1->_left = nullptr;
        delete tmp1;
    }
    
}

template<typename T>
int BinarySearchTree<T>::height()
{
    return height(_root)-1;
}

template<typename T>
int BinarySearchTree<T>::height(Node<T>* node)
{
    if (!node)
    {
        return 0;
    }
    else
    {
        int h_left = height(node->_left);
        int h_right = height(node->_right);
        
        if (h_left >= h_right)
        {
            return h_left+1;
        }
        else
        {
            return h_right+1;
        }
    }
}

template<typename T>
void BinarySearchTree<T>::display()
{
    std::cout << std::endl;
    display(_root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::display(Node<T>* node)
{
    display("", node, false);
}

template<typename T>
void BinarySearchTree<T>::display(std::string str, Node<T>* node, bool is_left)
{
    if (node != nullptr)
    {
        std::cout << str;
        std::cout << (is_left ? "├──" : "└──" );
        std::cout << *(node->_data) << std::endl;
        display(str + (is_left ? "│   " : "    "), node->_left, true);
        display(str + (is_left ? "│   " : "    "), node->_right, false);
    }
}


template<typename T>
int BinarySearchTree<T>::search_char(char data)
{
    return search_char(_root, data);
}

template<typename T>
int BinarySearchTree<T>::search_char(Node<T>* node, char data)
{
    if(!node)
    {
        return 0;
    }
    if((*node->_data)[0] < data)
    {
        return search_char(node->_right, data);
    }
    else if((*node->_data)[0] > data)
    {
        return search_char(node->_left, data);
    }
    else
    {
        return 1 + search_char(node->_right, data) + search_char(node->_left, data);
    }
}

template<typename T>
void BinarySearchTree<T>::remove_char(char data)
{
    remove_char(_root, data);
}

template<typename T>
void BinarySearchTree<T>::remove_char(Node<T>* node, char data)
{
    if (!node)
    {
        return;
    }
    if ((*node->_data)[0] < data)
    {
        remove_char(node->_right, data);
    }
    else if ((*node->_data)[0] > data)
    {
        remove_char(node->_left, data);
    }
    else
    {
        Node<T>* tmp = node->_parent;
        remove(node);
        remove_char(tmp, data);
        
    }
}

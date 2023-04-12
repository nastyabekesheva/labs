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
public:
    BinarySearchTree(): _root(nullptr) {}
    ~BinarySearchTree<T>();
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
    template<typename U>
    friend std::ostream & operator << (std::ostream &out, const BinarySearchTree<U> &tree);
    template<typename U>
    friend std::ostream & display(std::ostream &out, std::string str, Node<T>* node, bool is_left);
    template<typename U>
    friend std::istream & operator >> (std::istream &in,  BinarySearchTree<T> &tree);
    int search_char(char data);
    int search_char(Node<T>* node, char data);
    void remove_char(char data);
    void remove_char(Node<T>* node, char data);
};

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    if (_root)
    {
        delete _root; //    cleaning memory
    }
}

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
        inorder_tree_walk(node->_left); //    recur on left child
        std::cout << *(node->_data) << " ";
        inorder_tree_walk(node->_right); //    recur on right child
    }
}

template<typename T>
void BinarySearchTree<T>::insert(T data)
{
    if (!_root) //    if there is no root
    {
        _root = new Node<T>(data); //    create root
    }
    else
    {
        insert(_root, data);
    }
}

template<typename T>
void BinarySearchTree<T>::insert(Node<T>* node, T data)
{
    if (data > *(node->_data)) //    if key is greater than node's key
    {
        if (!node->_right) //    if there is no a right child
        {
            node->_right = new Node<T>(data, node); //    insert node on the right
        }
        else
        {
            insert(node->_right, data); //    go further right
        }
    }
    else if (data < *(node->_data)) //    if key is less than node's key
    {
        if (!node->_left) //    if there is no a left child
        {
            node->_left = new Node<T>(data, node); //    insert node on the left
        }
        else
        {
            insert(node->_left, data); //    go further left
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
    while (node && data != *(node->_data)) //    while there is node and its key differs from what we need to find
    {
        if (data < *(node->_data)) //    if key is less than node's key
        {
            node = node->_left; //    go further left
        }
        else
        {
            node = node->_right; //    go further right
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
    if(!node) //    just being cautious
    {
        node = _root;
    }
    while (node->_left) //    while there is a left child
    {
        node = node->_left; //    go further left
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
    if(!node) //    just being cautious
    {
        node = _root;
    }
    while (node->_right) //    while there is a right child
    {
        node = node->_right; //    go further right
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
    if (node->_right) //    if there is a right child
    {
        return min(node->_right);
    }
    Node<T>* tmp = node->_parent;
    while (tmp && node == tmp->_right) //    while there is a parent to node and node is a right child
    {
        node = tmp; //    move nodes
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
    if (node->_left) //    if there is a left child
    {
        return max(node->_left);
    }
    Node<T>* tmp = node->_parent;
    while (tmp && node == tmp->_left) //    while there is a parent to node and node is a left child
    {
        node = tmp; //    move nodes
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
    if (_root) //    nothing to remove if there's no root
    {
        if (!node->_left || !node->_right) //    here we mark a node that is going to be deleted
        {
            tmp1 = node;
        }
        else
        {
            tmp1 = successor(node);
        }
        
        if (tmp1->_left) //    here we mark a child of node that is going to be deleted
        {
            tmp2 = tmp1->_left;
        }
        else
        {
            tmp2 = tmp1->_right;
        }
        if (tmp2) //    if there is a child
        {
            tmp2->_parent = tmp1->_parent; //    move parents
        }
        if (!tmp1->_parent) //    if node to be deleted is a root
        {
            _root = tmp2; //    its child becomes a root
        }
        else if (tmp1 == tmp1->_parent->_left) //    if node to be deleted is a left child
        {
            tmp1->_parent->_left = tmp2; //    move up its child left
        }
        else
        {
            tmp1->_parent->_right = tmp2; //    move up its child right
        }
        if (tmp1 != node) //    if the node we removed is the 'node'
        {
            T* tmp_data = node->_data; //    move keys
            node->_data = tmp1->_data;
            delete tmp_data;
            tmp1->_data = nullptr;
        }
        tmp1->_right = tmp1->_left = nullptr; //    unbind nodes
        delete tmp1; //    actually delete node
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
        int h_left = height(node->_left); //    find height of left child
        int h_right = height(node->_right); //    find height of right child
        
        if (h_left >= h_right) // use the larger child
        {
            return h_left+1;
        }
        else
        {
            return h_right+1;
        }
    }
}

/*          That's just visualization magic          */

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

/*          Magic ends here          */


template<typename T>
int BinarySearchTree<T>::search_char(char data)
{
    return search_char(_root, data);
}

template<typename T>
int BinarySearchTree<T>::search_char(Node<T>* node, char data)
{
    if(!node) //    if there is no root...
    {
        return 0;
    }
    if((*node->_data)[0] < data) //    if key's first char less than data
    {
        return search_char(node->_right, data); //    go right
    }
    else if((*node->_data)[0] > data) //    if key's first char greater than data
    {
        return search_char(node->_left, data); //    go left
    }
    else
    {
        return 1 + search_char(node->_right, data) + search_char(node->_left, data); //    we found one key, lets try to find some more!
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
    if (!node) //    if there is no root...
    {
        return;
    }
    if ((*node->_data)[0] < data) //    if key's first char less than data
    {
        remove_char(node->_right, data); //    go right
    }
    else if ((*node->_data)[0] > data) //    if key's first char greater than data
    {
        remove_char(node->_left, data); //    go left
    }
    else
    {
        Node<T>* tmp = node->_parent;
        remove(node); //    remove what we found
        remove_char(tmp, data); //    lets try to remove more nodes
        
    }
}

/*          More magic          */

template<typename T>
std::ostream & operator << (std::ostream &out, const BinarySearchTree<T> &tree)
{
    return display(out, "", tree._root, false);
}

template<typename T>
std::ostream & display(std::ostream &out, std::string str, Node<T>* node, bool is_left)
{
    if (node != nullptr)
    {
        out << str; //    that's like a prefix of sorts
        out << (is_left ? "├──" : "└──" ); //    if the node is a left child
        out << *(node->_data) << std::endl; //    that's our data
        display(out, str + (is_left ? "│   " : "    "), node->_left, true); //    print left child
        display(out, str + (is_left ? "│   " : "    "), node->_right, false); //    print right child
    }
    return out;
}

template<typename T>
std::istream & operator >> (std::istream &in, BinarySearchTree<T> &tree)
{

    std::string tmp;
    while (tmp != "/~") //    just a way to stop stream
    {
        in >> tmp;
        if (tmp != "/~") //    we don't want to inser "/~" into tree
        {
            std::istringstream iss(tmp);
            T f;
            iss >> std::noskipws >> f;
            tree.insert(f);
        }
    }
    return in;
}

/*          Magic ends here          */

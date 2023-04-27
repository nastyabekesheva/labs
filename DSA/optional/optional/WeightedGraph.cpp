//
//  WeightedGraph.cpp
//  optional
//
//  Created by Nastya Bekesheva on 26.04.2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

template<typename T>
struct Node
{
    std::shared_ptr<T> _data;
    Node(T data)
    {
        _data = std::make_shared<T>(data);
    }
    Node(const Node &node)
    {
        _data = node._data;
    }
    Node(Node && node)
    {
        T* tmp = node._data;
        node._data = _data;
        _data = tmp;
    }
    Node& operator=(const Node & node)
    {
        _data = node._data;
    }
    Node& operator=(Node && node)
    {
        T* tmp = node._data;
        node._data = _data;
        _data = tmp;
    }
    ~Node() = default;
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<int> node) {
    os << *(node._data);
    return os;
}

template<typename T1, typename T2>
bool operator< (const Node<T1>& lhs, const Node<T2>& rhs)
{
    return *(lhs._data) < *(rhs._data);
}

template<typename T1, typename T2>
bool operator> (const Node<T1>& lhs, const Node<T2>& rhs)
{
    return *(lhs._data) > *(rhs._data);
}

template<typename T1, typename T2>
bool operator<= (const Node<T1>& lhs, const Node<T2>& rhs)
{
    return *(lhs._data) <= *(rhs._data);
}

template<typename T1, typename T2>
bool operator>= (const Node<T1>& lhs, const Node<T2>& rhs)
{
    return *(lhs._data) >= *(rhs._data);
}

template<typename T1, typename T2>
bool operator== (const Node<T1>& lhs, const Node<T2>& rhs)
{
    return *(lhs._data) == *(rhs._data);
}

template<typename T1, typename T2>
bool operator!= (const Node<T1>& lhs, const Node<T2>& rhs)
{
    return *(lhs._data) == *(rhs._data);
}

template<typename T>
struct Edge
{
    std::shared_ptr<Node<T>> _start;
    std::shared_ptr<Node<T>> _end;
    int _weight;
    Edge(): _start(nullptr), _end(nullptr), _weight(0) {}
    Edge(std::shared_ptr<Node<T>> start, std::shared_ptr<Node<T>> end, int weight = 0): _start(start), _end(end), _weight(weight) {}
    Edge(T start, T end, int weight = 0)
    {
        std::shared_ptr<Node<T>> start_node = new Node<T>(start);
        std::shared_ptr<Node<T>> end_node = new Node<T>(end);
        _start = start_node;
        _end = end_node;
        _weight = weight;
    }
    Edge(const Edge &edge)
    {
        _start = edge._start;
        _end = edge._end;
        _weight = edge._weight;
    }
    Edge(Edge && edge)
    {
        std::shared_ptr<Node<T>> tmp1 = edge._start;
        std::shared_ptr<Node<T>> tmp2 = edge._end;
        int tmp3 = edge._weight;
        edge._start = _start;
        _start = tmp1;
        edge._end = _end;
        _end = tmp2;
        edge._weight = _weight;
        _weight = tmp3;
    }
    Edge& operator=(const Edge & edge)
    {
        _start = edge._start;
        _end = edge._end;
        _weight = edge._weight;
    }
    Edge& operator=(Edge && edge)
    {
        std::shared_ptr<Node<T>> tmp1 = edge._start;
        std::shared_ptr<Node<T>> tmp2 = edge._end;
        int tmp3 = edge._weight;
        edge._start = _start;
        _start = tmp1;
        edge._end = _end;
        _end = tmp2;
        edge._weight = _weight;
        _weight = tmp3;
    }
    ~Edge() = default;
    bool operator<(const Edge& other) const
    {
        return _weight < other._weight;
    }
    bool operator>(const Edge& other) const
    {
        return _weight > other._weight;
    }
};

//template<typename T1, typename T2>
//bool operator< (const Edge<T1> lhs, const Edge<T2> rhs)
//{
//    return *(lhs._weight) < *(rhs._weight);
//}
//
//template<typename T1, typename T2>
//bool operator> (const Edge<T1>& lhs, const Edge<T2>& rhs)
//{
//    return *(lhs._weight) > *(rhs._weight);
//}

template<typename T>
class WeightedGraph
{
private:
    std::vector<std::shared_ptr<Node<T>>> _vertices;
    std::vector<std::shared_ptr<Edge<T>>> _edges;
    std::vector<std::vector<int>> _adj_matrix;
    std::vector<std::vector<std::shared_ptr<Node<T>>>> _adj_lists;
    int _num_edges;
    int _num_vertices;
    void make_matrix();
    void make_lists();
    bool is_an_edge(std::shared_ptr<Node<T>> vertex1, std::shared_ptr<Node<T>> vertex2);
    std::shared_ptr<Edge<T>> find_edge(std::shared_ptr<Node<T>> vertex1, std::shared_ptr<Node<T>> vertex2);
    int partition(int low, int high);
    void quick_sort(int low, int high);
    void sort_by_weight();
public:
    WeightedGraph(): _vertices({}), _edges({}), _adj_matrix({{}}), _num_edges(0) {}
    WeightedGraph(std::vector<std::shared_ptr<Node<T>>> vertecies, std::vector<std::shared_ptr<Edge<T>>> edges = {});
    ~WeightedGraph() = default;
    WeightedGraph(const WeightedGraph & wg);
    WeightedGraph(WeightedGraph && wg);
    WeightedGraph& operator=(const WeightedGraph & wg);
    WeightedGraph& operator=(WeightedGraph && wg);
    void print_adj_matrix();
    void print_adj_lists();
    void add_node(std::shared_ptr<Node<T>> node);
    void add_node(T data);
    void remove_node(std::shared_ptr<Node<T>> node);
    void add_edge(std::shared_ptr<Edge<T>> edge);
    void add_edge(T start, T end, int weight);
    void remove_edge(std::shared_ptr<Edge<T>> edge);
    std::vector<std::shared_ptr<Node<T>>> DFS(std::shared_ptr<Node<T>> start);
    std::vector<std::shared_ptr<Node<T>>> BFS(std::shared_ptr<Node<T>> start);
    std::vector<std::shared_ptr<Edge<T>>> kruskal();
    
};


template<typename T>
bool WeightedGraph<T>::is_an_edge(std::shared_ptr<Node<T>> vertex1, std::shared_ptr<Node<T>> vertex2)
{
    for (std::shared_ptr<Edge<T>> edge : _edges)
    {
        if ((edge->_start == vertex1 && edge->_end == vertex2) || (edge->_start == vertex2 && edge->_end == vertex1))
            return true;
    }
    return false;
}

template<typename T>
std::shared_ptr<Edge<T>> WeightedGraph<T>::find_edge(std::shared_ptr<Node<T>> vertex1, std::shared_ptr<Node<T>> vertex2)
{
    for (std::shared_ptr<Edge<T>> edge : _edges)
    {
        if ((edge->_start == vertex1 && edge->_end == vertex2) || (edge->_start == vertex2 && edge->_end == vertex1))
            return edge;
    }
    return nullptr;
}

template<typename T>
void WeightedGraph<T>::make_matrix()
{
    _adj_matrix.clear();
    for (int i = 0; i < _num_vertices; i++)
    {
        _adj_matrix.push_back(std::vector<int>());
        for (int j = 0; j < _num_vertices; j++)
        {
            if (is_an_edge(_vertices[i], _vertices[j]))
            {
                _adj_matrix[i].push_back(find_edge(_vertices[i], _vertices[j])->_weight);
            }
            else
            {
                _adj_matrix[i].push_back(0);
            }
        }
    }
}

template<typename T>
void WeightedGraph<T>::make_lists()
{
    _adj_lists.clear();
    for (int i = 0; i < _num_vertices; i++)
    {
        _adj_lists.push_back(std::vector<std::shared_ptr<Node<T>>>());
        for (int j = 0; j < _num_vertices; j++)
        {
            if (is_an_edge(_vertices[i], _vertices[j]))
            {
                _adj_lists[i].push_back(_vertices[j]);
            }
        }
    }
}

template<typename T>
WeightedGraph<T>::WeightedGraph(std::vector<std::shared_ptr<Node<T>>> vertecies, std::vector<std::shared_ptr<Edge<T>>> edges)
{
    _vertices = vertecies;
    _edges = edges;
    _num_edges = edges.size();
    _num_vertices = vertecies.size();
    make_matrix();
    make_lists();
    
}


template<typename T>
void WeightedGraph<T>::print_adj_matrix()
{
    std::cout << "  ";
    std::vector<T> data = {};
    for (std::shared_ptr<Node<T>> node : _vertices)
    {
        data.push_back(*node->_data);
    }
    for (const auto& cell : data)
    {
        std::cout << std::setw(2) << cell << "   ";
    }
    std::cout << std::endl;
    
    // Print top border
    std::cout << "+";
    for (size_t i = 0; i < _adj_matrix[0].size() * 5 - 1; i++)
    {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
    
    int i = 0;

    for (const auto& row : _adj_matrix)
    {
        std::cout << "| ";
        for (const auto& cell : row)
        {
            std::cout << std::setw(2) << cell << " | ";
        }
        std::cout << " " << data[i] << std::endl;

        // Print separator between rows
        std::cout << "+";
        for (size_t i = 0; i < row.size() * 5 - 1; i++)
        {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
        i++;
    }
}

template<typename T>
void WeightedGraph<T>::print_adj_lists()
{
    for (int i = 0; i < _num_vertices; i++)
    {
        std::cout << " |" << *(_vertices[i])->_data << "| :  {";
        for (int j = 0; j < _adj_lists[i].size(); j++)
        {
            std::cout << " " << *(_adj_lists[i][j])->_data << " ";
        }
        std::cout << "}" << std::endl;
    }
}

template<typename T>
void WeightedGraph<T>::add_node(std::shared_ptr<Node<T>> node)
{
    if (node && (std::find(_vertices.begin(), _vertices.end(), node) != _vertices.end()))
    {
        _vertices.push_back(node);
        _num_vertices++;
        make_matrix();
        make_lists();
    }
}

template<typename T>
void WeightedGraph<T>::add_node(T data)
{
    std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>>(data);
    add_node(tmp);
//    delete tmp;
}

template<typename T>
void WeightedGraph<T>::remove_node(std::shared_ptr<Node<T>> node)
{
    std::vector<std::shared_ptr<Edge<T>>> to_be_removed;
    if (std::find(_vertices.begin(), _vertices.end(), node) != _vertices.end())
    {
        for (std::shared_ptr<Edge<T>> edge : _edges)
        {
            if (edge->_start == node || edge->_end == node)
                to_be_removed.push_back(edge);
//                remove_edge(edge);
        }
        _num_vertices--;
    }
    for (std::shared_ptr<Edge<T>> edge : to_be_removed)
    {
        remove_edge(edge);
    }
}

template<typename T>
void WeightedGraph<T>::remove_edge(std::shared_ptr<Edge<T>> edge)
{
    if (std::find(_edges.begin(), _edges.end(), edge) != _edges.end())
    {
        _edges.erase(std::remove(_edges.begin(), _edges.end(), edge), _edges.end());
        _num_edges--;
        make_matrix();
        make_lists();
    }
}

template<typename T>
void WeightedGraph<T>::add_edge(std::shared_ptr<Edge<T>> edge)
{
    if (!(edge->_start && (std::find(_vertices.begin(), _vertices.end(), edge->_start) != _vertices.end())))
    {
        _vertices.push_back(edge->_start);
    }
    if ((!edge->_end && (std::find(_vertices.begin(), _vertices.end(), edge->_end) != _vertices.end())))
    {
        _vertices.push_back(edge->_end);
    }
    if (edge && !(std::find(_edges.begin(), _edges.end(), edge) != _edges.end()))
    {
        _edges.push_back(edge);
        _num_edges++;
        make_matrix();
        make_lists();
    }
}

template<typename T>
void WeightedGraph<T>::add_edge(T start, T end, int weight)
{
    std::shared_ptr<Edge<T>> tmp = new Edge<T>(start, end, weight);
    add_edge(tmp);
//    delete tmp;
}

template<typename T>
std::vector<std::shared_ptr<Node<T>>> WeightedGraph<T>::BFS(std::shared_ptr<Node<T>> start)
{
    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(start);
    std::vector<std::shared_ptr<Node<T>>> visited;
    visited.push_back(start);
    
    std::vector<std::shared_ptr<Node<T>>> bfs;
    
    while (!q.empty())
    {
        std::shared_ptr<Node<T>> node = q.front();
        q.pop();
        bfs.push_back(node);
        
        int i = std::distance(_vertices.begin(), std::find(_vertices.begin(), _vertices.end(), node));
        for (std::shared_ptr<Node<T>> adj_node : _adj_lists[i])
        {
            if (!(std::find(visited.begin(), visited.end(), adj_node) != visited.end()))
            {
                visited.push_back(adj_node);
                q.push(adj_node);
            }
        }
    }
    
    std::cout << "BFS";
    for (std::shared_ptr<Node<T>> node : bfs)
    {
        std::cout << " -> " << *(node->_data);
    }
    std::cout << std::endl;
    
    return bfs;
    
}

template<typename T>
std::vector<std::shared_ptr<Node<T>>> WeightedGraph<T>::DFS(std::shared_ptr<Node<T>> start)
{
    std::stack<std::shared_ptr<Node<T>>> s;
    s.push(start);
    std::vector<std::shared_ptr<Node<T>>> visited;
    visited.push_back(start);
    
    std::vector<std::shared_ptr<Node<T>>> dfs;
    
    while (!s.empty())
    {
        std::shared_ptr<Node<T>> node = s.top();
        s.pop();
        dfs.push_back(node);
        
        int i = std::distance(_vertices.begin(), std::find(_vertices.begin(), _vertices.end(), node));
        for (std::shared_ptr<Node<T>> adj_node : _adj_lists[i])
        {
            if (!(std::find(visited.begin(), visited.end(), adj_node) != visited.end()))
            {
                visited.push_back(adj_node);
                s.push(adj_node);
            }
        }
    }
    
    std::cout << "DFS";
    for (std::shared_ptr<Node<T>> node : dfs)
    {
        std::cout << " -> " << *(node->_data);
    }
    std::cout << std::endl;
    
    return dfs;
}

/*          based on quicksort          */

template<typename T>
int WeightedGraph<T>::partition(int low, int high)
{
    std::shared_ptr<Edge<T>> pivot = _edges[high];
    int i = (low - 1);
    
    for (int j = low; j <= high-1; j++)
    {
        if (*_edges[j] < *pivot)
        {
            i++;
            std::swap(_edges[i], _edges[j]);
        }
    }
    
    std::swap(_edges[i + 1], _edges[high]);
    return (i + 1);
}

template<typename T>
void WeightedGraph<T>::quick_sort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        
        quick_sort(low, pi-1);
        quick_sort(pi+1, high);
    }
}

template<typename T>
void WeightedGraph<T>::sort_by_weight()
{
    quick_sort(0, _num_edges-1);
}

template<typename T>
std::vector<std::shared_ptr<Edge<T>>> WeightedGraph<T>::kruskal()
{
    sort_by_weight();
    return _edges;
}



//
//  main.cpp
//  optional
//
//  Created by Nastya Bekesheva on 26.04.2023.
//

#include <iostream>
#include "WeightedGraph.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Worl" << std::endl;
    Node<int>* n0 = new Node<int>(0);
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    Node<int>* n4 = new Node<int>(4);
    std::vector<Node<int>*> v = {n0, n1, n2, n3, n4};
    Edge<int>* e0 = new Edge<int>(n0, n1, 2);
    Edge<int>* e1 = new Edge<int>(n0, n2, 3);
    Edge<int>* e2 = new Edge<int>(n1, n2, 15);
    Edge<int>* e3 = new Edge<int>(n3, n1, 2);
    Edge<int>* e4 = new Edge<int>(n3, n4, 9);
    Edge<int>* e5 = new Edge<int>(n2, n4, 13);
    std::vector<Edge<int>*> e = {e0, e1, e2, e3, e4, e5};
    WeightedGraph<int> wg = WeightedGraph<int>(v, e);
    wg.print_adj_matrix();
    wg.remove_node(n4);
    wg.print_adj_matrix();
    wg.add_node(n4);
    wg.add_edge(e4);
    wg.add_edge(e5);
    wg.print_adj_matrix();
    wg.print_adj_lists();
    wg.BFS(n0);
    wg.DFS(n0);
    return 0;
}

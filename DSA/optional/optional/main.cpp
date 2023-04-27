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
    std::shared_ptr<Node<int>> n0 = std::make_shared<Node<int>>(0);
    std::shared_ptr<Node<int>> n1 = std::make_shared<Node<int>>(1);
    std::shared_ptr<Node<int>> n2 = std::make_shared<Node<int>>(2);
    std::shared_ptr<Node<int>> n3 = std::make_shared<Node<int>>(3);
    std::shared_ptr<Node<int>> n4 = std::make_shared<Node<int>>(4);
    std::vector<std::shared_ptr<Node<int>>> v = {n0, n1, n2, n3, n4};
    std::shared_ptr<Edge<int>> e0 = std::make_shared<Edge<int>>(n0, n1, 2);
    std::shared_ptr<Edge<int>> e1 = std::make_shared<Edge<int>>(n0, n2, 3);
    std::shared_ptr<Edge<int>> e2 = std::make_shared<Edge<int>>(n1, n2, 15);
    std::shared_ptr<Edge<int>> e3 = std::make_shared<Edge<int>>(n3, n1, 2);
    std::shared_ptr<Edge<int>> e4 = std::make_shared<Edge<int>>(n3, n4, 9);
    std::shared_ptr<Edge<int>> e5 = std::make_shared<Edge<int>>(n2, n4, 13);
    std::vector<std::shared_ptr<Edge<int>>> e = {e0, e1, e2, e3, e4, e5};
    WeightedGraph<int> wg = WeightedGraph<int>(v, e);
    wg.print_adj_matrix();
    wg.remove_node(n4);
    wg.print_adj_matrix();
    wg.add_node(n4);
    wg.add_node(4);
    wg.add_edge(e4);
    wg.add_edge(e5);
    wg.print_adj_matrix();
    wg.print_adj_lists();
    wg.BFS(n0);
    wg.DFS(n0);
    std::cout << *n0.get()->_data;
    return 0;
}

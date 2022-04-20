//
//  main.swift
//  Graph
//
//  Created by Nastya Bekesheva on 07.04.2022.
//

import Foundation

class Node{
    private var name: String = ""
    
    init(name: String){
        self.name = name
    }
    
    func getName() -> String {
        return self.name
    }
}

extension Node: Equatable {
    static func ==(_ nodeOne: Node, _ nodeTwo: Node) -> Bool {
        return nodeOne.name == nodeTwo.name
    }
}

class Graph{
    private var nodes: [Node] = []
    var edges: [(nodeOne: Node, nodeTwo: Node)] = []
    
    init(nodes: [Node]){
        self.nodes = nodes
    }
    
    func addNode(node: Node){
        self.nodes.append(node)
        print("Adding node \(node.getName()) to the graph...")
    }
    
    func getNodes() -> [Node]{
        return nodes
    }
    
    func printNodes(){
        for node in nodes{
            print(node.getName(), terminator: " ")
        }
    }
    
    func addEdge(nodeOne: Node, nodeTwo: Node){
        if nodes.contains{ $0 === nodeOne } && nodes.contains{ $0 === nodeTwo }{
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph...")
        }
        else if nodes.contains{ $0 === nodeOne } && !nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph...")
        }
        else if !nodes.contains{ $0 === nodeOne } && nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeOne.getName())")
            self.addNode(node: nodeOne)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph...")
        }
        else{
            print("Missing node: \(nodeOne.getName())")
            self.addNode(node: nodeOne)
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph...")
        }
    }
    
    func DFS(startNode: Node) -> String{
        var dfs = ""
        var stack = [startNode]
        var visited: [Node] = []

        while !stack.isEmpty{
            var v = stack.popLast()
            
            if !visited.contains{ $0 === v }{

                for edge in self.edges{
                    if edge.nodeOne == v && !visited.contains{ $0 === edge.nodeTwo }{
                        stack.append(edge.nodeTwo)
                        
                    }
                    else if edge.nodeTwo == v && !visited.contains{ $0 === edge.nodeOne  }{
                        stack.append(edge.nodeOne)
                    }
                }
                visited.append(v!)
            }
            dfs += "\(v!.getName()) "
        }
        return dfs
    }
    
    func BFS(startNode: Node) -> String{
        var bfs = ""
        var queqe = [startNode]
        var visited: [Node] = []
        
        while !queqe.isEmpty{
            var v = queqe.removeFirst()
            bfs += "\(v.getName()) "
            
            for edge in self.edges {
                if edge.nodeOne == v && !visited.contains{ $0 === edge.nodeTwo }{
                    queqe.append(edge.nodeTwo)
                    
                }
                else if edge.nodeTwo == v && !visited.contains{ $0 === edge.nodeOne  }{
                    queqe.append(edge.nodeOne)
                }
            }
            
            visited.append(v)
        }
        
        return bfs
    }

}

let node1 = Node(name: "1")
let node2 = Node(name: "2")
let node3 = Node(name: "3")
let node4 = Node(name: "4")
let node5 = Node(name: "5")

var g = Graph(nodes: [node1, node2, node3, node4, node5])
g.addEdge(nodeOne: node1, nodeTwo: node2)
g.addEdge(nodeOne: node3, nodeTwo: node4)
g.addEdge(nodeOne: node2, nodeTwo: node5)
g.addEdge(nodeOne: node1, nodeTwo: node4)

print(g.DFS(startNode: node1))
print(g.BFS(startNode: node1))


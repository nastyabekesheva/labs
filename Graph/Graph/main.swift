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

class Graph{
    private var nodes: [Node] = []
    private var edges: [(nodeOne: Node, nodeTwo: Node)] = []
    
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
    
    func DFS(){
        
    }
    
}

let node1 = Node(name: "1")
let node2 = Node(name: "2")
let node3 = Node(name: "3")

var g = Graph(nodes: [node1, node2, node3])
g.printNodes()
g.addEdge(nodeOne: node1, nodeTwo: node2)
g.addEdge(nodeOne: node3, nodeTwo: Node(name: "4"))

dump(g)

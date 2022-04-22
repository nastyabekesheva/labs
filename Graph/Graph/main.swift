//
//  main.swift
//  Graph
//
//  Created by Nastya Bekesheva on 07.04.2022.
//

import Foundation

class Node: Hashable{
    private var name: String = ""
    
    init(name: String){
        self.name = name
    }
    
    func getName() -> String {
        return self.name
    }
    
    func hash(into hasher: inout Hasher) {
        hasher.combine(name)
    }
}

extension Node: Equatable {
    static func ==(_ nodeOne: Node, _ nodeTwo: Node) -> Bool {
        return nodeOne.name == nodeTwo.name
    }
}

class Graph{
    var nodes: [Node] = []
    var edges: [(nodeOne: Node, nodeTwo: Node)] = []
    var adjacencyList: [Node: [Node]] = [:]
    var adjacencyMatrix: [Node: [Int]] = [:]
    
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
    
    func fillList() -> [Node: [Node]]{

        for node in nodes {
            self.adjacencyList[node] = []
        }

        for edge in edges {
            if !adjacencyList[edge.nodeOne]!.contains{ $0 === edge.nodeTwo}{
                adjacencyList[edge.nodeOne]!.append(edge.nodeTwo)
                adjacencyList[edge.nodeTwo]!.append(edge.nodeOne)
            }

        }

        return adjacencyList
    }
    
    func fillMatrix() -> [Node: [Int]]{
        
        for node in nodes {
            self.adjacencyMatrix[node] = []
        }
        
        for nodeOne in nodes{
            for nodeTwo in nodes{
                if !adjacencyList[nodeOne]!.contains{ $0 === nodeTwo }{
                    adjacencyMatrix[nodeOne]!.append(0)
                }
                else{
                    adjacencyMatrix[nodeOne]!.append(1)
                }
            }
        }
        
        return adjacencyMatrix

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
    
    func DFS(startNode: Node) -> [Node]{
        
        var dfs: [Node] = []
        var stack = [startNode]
        var visited: [Node] = []

        while !stack.isEmpty{
            let v = stack.popLast()
            
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
            dfs.append(v!)
        }
        return dfs
        
    }
    
    func BFS(startNode: Node) -> [Node]{
        var bfs: [Node] = []
        var queqe = [startNode]
        var visited: [Node] = []
        
        while !queqe.isEmpty{
            let v = queqe.removeFirst()
            bfs.append(v)
            
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
    
    func amountOfWalks(nodeOne: Node, nodeTwo: Node, length: Int) -> (Int, [Node: [Int]]){
        var result = adjacencyMatrix
        var answer: Int = 0
        var matrix: [[Int]] = []
        var resultMatrix: [[Int]] = []
        var len = length
        
        for node in nodes{
            matrix.append(adjacencyMatrix[node]!)
            resultMatrix.append(adjacencyMatrix[node]!)
        }
        
        while len > 1{
            for i in 1...nodes.count-1{
                for j in 1...nodes.count-1{
                    for k in 1...nodes.count-1{
                        resultMatrix[i][j] += matrix[i][k] * resultMatrix[k][j]
                    }
                }
            }
            len -= 1
        }
        for i in 0...nodes.count-1{
            result[nodes[i]] = resultMatrix[i]
        }
        
        answer = result[nodeOne]![nodes.firstIndex(of: nodeTwo)!]
     
        return (answer, result)
    }
    
    func warshall() -> [[Bool]]{
        
        var matrixInt: [[Int]] = []
        var matrix: [[Bool]] = []
        var warshall: [[Bool]] = []
        
        for node in nodes{
            matrixInt.append(adjacencyMatrix[node]!)
        }
        
        for i in 0...nodes.count-1{
            matrix.append([])
            warshall.append([])
            for _ in 0...nodes.count-1{
                matrix[i].append(false)
                warshall[i].append(false)
            }
        }
        
        
        for i in 0...nodes.count-1{
            for j in 0...nodes.count-1{
                if matrixInt[i][j] == 0{
                    matrix[i][j] = false
                }
                else{
                    matrix[i][j] = true
                }
            }
        }
        
        for i in 0...nodes.count-1{
            for j in 0...nodes.count-1{
                for k in 0...nodes.count-1{
                    warshall[i][j] = warshall[i][j] || (warshall[i][k] && warshall[k][j])
                 }
            }
        }
        
        for i in 0...nodes.count-1{
            warshall[i][i] = true
        }
        
        return warshall
    }

}

class WeightedGraph: Graph{
    
    var weightedEdges: [(nodeOne: Node, nodeTwo: Node, weight: Int)] = []
    
    override init(nodes: [Node]){
        super.init(nodes: nodes)
        
    }
    
    func addEdge(nodeOne: Node, nodeTwo: Node, weight: Int) {
        if nodes.contains{ $0 === nodeOne } && nodes.contains{ $0 === nodeTwo }{
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            weightedEdges.append((nodeOne: nodeOne, nodeTwo: nodeTwo, weight: weight))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph...")
        }
        else if nodes.contains{ $0 === nodeOne } && !nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            weightedEdges.append((nodeOne: nodeOne, nodeTwo: nodeTwo, weight: weight))
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
            weightedEdges.append((nodeOne: nodeOne, nodeTwo: nodeTwo, weight: weight))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph...")
        }
        
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
g.addEdge(nodeOne: node3, nodeTwo: node5)
g.fillList()
g.fillMatrix()
g.amountOfWalks(nodeOne: node2, nodeTwo: node3, length: 5)




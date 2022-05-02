//
//  main.swift
//  Graph
//
//  Created by Nastya Bekesheva on 07.04.2022.
//

import Foundation

extension Int{
    static func inf() -> String{ return "inf"}
}

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

extension Array  {
    func contains<E1, E2>(_ tuple: (E1, E2)) -> Bool where E1: Equatable, E2: Equatable, Element == (E1, E2) {
        return contains { $0.0 == tuple.0 && $0.1 == tuple.1 }
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
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
        else if nodes.contains{ $0 === nodeOne } && !nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
        else if !nodes.contains{ $0 === nodeOne } && nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeOne.getName())")
            self.addNode(node: nodeOne)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
        else{
            print("Missing node: \(nodeOne.getName())")
            self.addNode(node: nodeOne)
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
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
        var temp: [[Int]] = []
        var resultMatrix: [[Int]] = []
        var length = length
        
        for node in nodes{
            matrix.append(adjacencyMatrix[node]!)
            resultMatrix.append(adjacencyMatrix[node]!)
        }
        for i in 0...nodes.count-1{
            temp.append([])
            for _ in 0...nodes.count-1{
                temp[i].append(0)
            }
        }

        for _ in 0...length-2{
            for i in 0...nodes.count-1{
                for j in 0...nodes.count-1{
                    for k in 0...nodes.count-1{
                        temp[i][j] += resultMatrix[i][k] * matrix[k][j]
                    }
                }
            }
            resultMatrix = temp
        }
        
        for i in 0...nodes.count-1{
            result[nodes[i]] = resultMatrix[i]
        }
        
        answer = result[nodeOne]![nodes.firstIndex(of: nodeTwo)!]
     
        return (answer, result)
    }
    
    func warshall() -> (matrix: [[Bool]], answer: Bool){
        
        var matrixInt: [[Int]] = []
        var matrix: [[Bool]] = []
        var answer: Bool
        
        for node in nodes{
            matrixInt.append(adjacencyMatrix[node]!)
        }
        
        for i in 0...nodes.count-1{
            matrix.append([])
            for _ in 0...nodes.count-1{
                matrix[i].append(false)
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
                    matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j])
                 }
            }
        }
        
        for i in 0...nodes.count-1{
            matrix[i][i] = true
        }
        
        if Array(matrix.joined()).contains(false){
            return (matrix, false)
        }
        else{
            return (matrix, true)
        }
        
    }
    
    func contains(whereToLook: [Node], what: [Node]) -> Bool{
        
        var answer = true
        
        for node in what{
            if !whereToLook.contains{ $0 === node }{
                answer = false
                break
            }
        }
        
        return answer
    }
    
    func getTreeIndex(tree: [Int: [Node]], node: Node) -> Int?{
        
        var answer: Int?
        for (key, value) in tree{
            if value.contains{ $0 === node }{
                answer = key
            }
        }
        
        return answer
    }
    
    func mergeTree(tree: [Int: [Node]],treeOfFirstNode: Int, treeOfSecondNode: Int) -> [Int: [Node]]{
        var newTree = tree
        if treeOfFirstNode != treeOfSecondNode{
            newTree[treeOfFirstNode]!.append(contentsOf: newTree[treeOfSecondNode]!)
            newTree.removeValue(forKey: treeOfSecondNode)
        }
        
        return newTree
    }
    
    func firsIndex(of: ( nodeOne: Node,  nodeTwo: Node)) -> Int?{
        for i in 0...edges.count-1{
            if edges[i].nodeOne == of.nodeOne && edges[i].nodeTwo == of.nodeTwo{
                return i
            }
        }
        
        return nil
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
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
        else if nodes.contains{ $0 === nodeOne } && !nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            weightedEdges.append((nodeOne: nodeOne, nodeTwo: nodeTwo, weight: weight))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
        else if !nodes.contains{ $0 === nodeOne } && nodes.contains{ $0 === nodeTwo }{
            print("Missing node: \(nodeOne.getName())")
            self.addNode(node: nodeOne)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
        else{
            print("Missing node: \(nodeOne.getName())")
            self.addNode(node: nodeOne)
            print("Missing node: \(nodeTwo.getName())")
            self.addNode(node: nodeTwo)
            edges.append((nodeOne: nodeOne, nodeTwo: nodeTwo))
            weightedEdges.append((nodeOne: nodeOne, nodeTwo: nodeTwo, weight: weight))
            print("Adding edge (\(nodeOne.getName()), \(nodeTwo.getName())) to the graph")
        }
    }
    
    func contains(whereToLook: [(nodeOne: Node, nodeTwo: Node, weight: Int)], what: [Node]) -> Bool{
        
        var visited: [Node] = []
        
        for node in what{
            for (nodeOne, nodeTwo, _) in whereToLook{
                if (node == nodeOne || node == nodeTwo) && !(visited.contains{ $0 === node }){
                    visited.append(node)
                    continue
                }
            }
        }
        if visited == nodes{
            return true
        }
        else{
            return false
        }
    }
    
    func kruskal() -> [(nodeOne: Node, nodeTwo: Node, weight: Int)]{
        let sortedWeightedEdges = weightedEdges.sorted(by: {$0.weight < $1.weight})
        var edgesToBeSorted = sortedWeightedEdges
        var forest: [(nodeOne: Node, nodeTwo: Node, weight: Int)] = []
        var tree: [Int: [Node]] = [:]
        
        for i in 0...nodes.count-1{
            tree.updateValue([nodes[i]], forKey: i+1)
        }
        
        while !edgesToBeSorted.isEmpty && !(tree[1]!.count == nodes.count)  {
            let edgePoped = edgesToBeSorted.removeFirst()
            var treeOfFirstNode = Int()
            var treeOfSecondNode = Int()
            
            treeOfFirstNode = self.getTreeIndex(tree: tree, node: edgePoped.nodeOne)!
            treeOfSecondNode = self.getTreeIndex(tree: tree, node: edgePoped.nodeTwo)!
            
            tree = self.mergeTree(tree: tree, treeOfFirstNode: treeOfFirstNode, treeOfSecondNode: treeOfSecondNode)
            
        }
        
        return forest
    }
    
    func prim(node: Node) -> [(nodeOne: Node, nodeTwo: Node, weight: Int)]{
        var edgesToBeAdded = weightedEdges
        var forest: [(nodeOne: Node, nodeTwo: Node, weight: Int)] = []
        var tree: [Int: [Node]] = [:]
        var treeOfFirstNode = Int()
        var treeOfSecondNode = Int()
        
        for i in 0...nodes.count-1{
            tree.updateValue([nodes[i]], forKey: i+1)
        }
        
        var treeKeys: [Int] = []
        
        for (key, _) in tree{
            treeKeys.append(key)
        }
        
        var edge = edgesToBeAdded.removeFirst()
        forest.append(edge)
        
        while !edgesToBeAdded.isEmpty && !(treeKeys.count == 1){

            var connectedEdges: [(nodeOne: Node, nodeTwo: Node, weight: Int)] = []
            
            for (nodeOne, nodeTwo, weight) in edgesToBeAdded{
                if nodeOne == edge.nodeOne || nodeTwo == edge.nodeOne || nodeOne == edge.nodeTwo || nodeTwo == edge.nodeTwo{
                    connectedEdges.append((nodeOne, nodeTwo, weight))
                }
            }
            connectedEdges = connectedEdges.sorted(by: {$0.weight < $1.weight})
            forest.append(connectedEdges[0])
            edgesToBeAdded = edgesToBeAdded.filter(){$0 != connectedEdges[0]}
            
            treeOfFirstNode = self.getTreeIndex(tree: tree, node: edge.nodeOne)!
            treeOfSecondNode = self.getTreeIndex(tree: tree, node: edge.nodeTwo)!
            
            tree = self.mergeTree(tree: tree, treeOfFirstNode: treeOfFirstNode, treeOfSecondNode: treeOfSecondNode)
            treeKeys = treeKeys.filter(){$0 != treeOfSecondNode}
            
            treeOfFirstNode = self.getTreeIndex(tree: tree, node: connectedEdges[0].nodeOne)!
            treeOfSecondNode = self.getTreeIndex(tree: tree, node: connectedEdges[0].nodeTwo)!
            
            tree = self.mergeTree(tree: tree, treeOfFirstNode: treeOfFirstNode, treeOfSecondNode: treeOfSecondNode)
            treeKeys = treeKeys.filter(){$0 != treeOfSecondNode}

            edge = connectedEdges[0]
            
        }
        
        return forest
        
    }
    
    func floydWarshall() -> [Node: [Double]]{
        var matrix: [Node: [Double]] = [:]
        
        for node in nodes{
            matrix[node] = []
            for i in 0...nodes.count-1{
                matrix[node]!.append(Double.infinity)
            }
        }
        
        for node in nodes{
            for i in 0...nodes.count-1{
                if node == nodes[i]{
                    matrix[node]![i] = 0.0
                }
                else{
                    for edge in edges{
                        if edge == (node, nodes[i]){
                            matrix[node]![i] = Double(weightedEdges[self.firsIndex(of: (nodeOne: node, nodeTwo: nodes[i]))!].weight)
                            matrix[nodes[i]]![nodes.firstIndex(of: node)!] = Double(weightedEdges[self.firsIndex(of: (nodeOne: node, nodeTwo: nodes[i]))!].weight)
                        }
                    }
                }
            }
        }
        
        var tempMatrix : [[Double]] = []
        for node in nodes{
            tempMatrix.append( matrix[node]!)
        }
        
        for k in 0...nodes.count-1{
            for i in 0...nodes.count-1{
                for j in 0...nodes.count-1{
                
                    let newDistance = tempMatrix[i][k] + tempMatrix[k][j]
                    if newDistance < tempMatrix[i][j]{
                        tempMatrix[i][j] = newDistance
                    }
                }
            }
        }
        
        for node in nodes{
            matrix[node] = tempMatrix[nodes.firstIndex(of: node)!]
        }
        
        return matrix
    }
    
    func dijkstra(source: Node) -> [Node: [Node: Double]]{
        var source = source
        var distance: [Node: [Node: Double]] = [:]
        var queue: [Node] = []
        
        for initialNode in nodes{
            distance[initialNode] = [:]
            for node in nodes{
                if node != source{
                    distance[initialNode]![node] = Double.infinity
                    queue.append(initialNode)
                }
                else{
                    distance[initialNode]![node] = 0
                }
            }
        }
        
        while !queue.isEmpty{
            var v: Node = source
            var newDistance = distance
            var key = distance[source]!.min { a, b in a.value < b.value }!.key
            if queue.contains{ $0 === key }{
                v = key
                newDistance[source] = newDistance[source]?.filter{ $0 != key }
            }
            else{
                
            }
            if queue.contains{ $0 === v }{
                queue = queue.filter { $0 != v }

                for node in adjacencyList[v]!{
                    if queue.contains{ $0 === node }{

                        var alt = Double.infinity

                        for edge in edges{
                            if edge == (v, node){
                                alt = distance[v]![node]! + Double(weightedEdges[self.firsIndex(of: (nodeOne: v, nodeTwo: node))!].weight)
                                break
                            }
                            else if edge == (node, v){
                                alt = distance[v]![node]! + Double(weightedEdges[self.firsIndex(of: (nodeOne: v, nodeTwo: node))!].weight)
                                break
                            }
                        }
                        if alt < distance[v]![node]!{
                            distance[v]![node] = alt
                        }

                    }
                }
                source = v
                dump(distance)
                continue
            }
            else{
                continue
            }
        }
        
        return distance
    }
}

extension Dictionary where Value: Equatable {
    func allKeys(forValue val: Value) -> [Key] {
        return self.filter { $1 == val }.map { $0.0 }
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


var wg = WeightedGraph(nodes: [node1, node2, node3, node4, node5])
wg.addEdge(nodeOne: node1, nodeTwo: node2, weight: 3)
wg.addEdge(nodeOne: node3, nodeTwo: node4, weight: 2)
wg.addEdge(nodeOne: node2, nodeTwo: node5, weight: 6)
wg.addEdge(nodeOne: node1, nodeTwo: node4, weight: 3)
wg.addEdge(nodeOne: node3, nodeTwo: node5, weight: 1)
wg.addEdge(nodeOne: node3, nodeTwo: node2, weight: 5)
wg.addEdge(nodeOne: node5, nodeTwo: node4, weight: 7)
wg.addEdge(nodeOne: node1, nodeTwo: node5, weight: 2)
wg.addEdge(nodeOne: node5, nodeTwo: node4, weight: 5)
wg.addEdge(nodeOne: node3, nodeTwo: node5, weight: 8)
wg.fillList()
wg.fillMatrix()
wg.kruskal()
wg.floydWarshall()
dump(wg.dijkstra(source: node1))


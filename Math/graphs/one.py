'''
    A programm to represent a graph as lists of adjacency.
    Using Depth-first search algorithm.
'''

graph = {
    'a' : ['b', 'c', 'e', 'h'],
    'b' : ['d'],
    'c' : ['i', 'j'],
    'd' : ['i'],
    'e' : ['f', 'j'],
    'f' : ['h'],
    'g' : ['h', 'i'],
    'h' : ['i'],
    'i' : ['j'],
    'j' : []
}

from collections import defaultdict
visited = set()
graph_t = defaultdict(list)

def transpose(graph):
    for start, ends in graph.items():
       for end in ends:
           graph_t[end].append(start)
    return graph_t
 
def union(graph, graph_t):
    for k, v in graph_t.items():
        if k in graph:
            graph[k].extend(v)
        else:
            graph[k] = v
    return graph
stack = []
def dfs(visited, graph, node):
    if node not in visited:
        visited.add(node)
        print ("Node: ", node)
        for i in graph.keys():
            if i not in visited and i not in stack and i in graph[node]:
                stack.insert(0, i)
        print("Stack: ", stack)
        for neighbour in stack:
            try:
                stack.remove(neighbour)
                dfs(visited, graph, neighbour)
            except ValueError as ve:
                dfs(visited, graph, neighbour)

def sort(graph):
    for i in graph:
        graph[i] = list(set(graph[i]))
    for i in graph:
        graph[i] = sorted(graph[i])
    return graph

graph_t = transpose(graph)
graph = union(graph, graph_t)
print("Lists of adjacency: \n")
for i in graph.keys():
    print(i, end = " : ")
    print(graph[i])
print("\n")
print("DFS:\n")
dfs(visited, graph, 'h')
print("\n")

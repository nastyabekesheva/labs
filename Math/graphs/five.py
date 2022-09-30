'''
    Bellman-Ford's algoritm to find the shortest paths.
'''
from collections import defaultdict

graph = {
    'a' : {'f' : 5, 'h' : 17},
    'b' : {'c' : 5, 'f' : 13, 'g' : 4, 'h' : 12},
    'c' : {},
    'd' : {'e' : 10, 'f' : 2},
    'e' : {},
    'f' : {},
    'g' : {},
    'h' : {}
}
nodes = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
graph_t = defaultdict(dict)

def transpose(graph):
    for start in graph.keys():
        for end in graph[start]:
            graph_t[end].update({ start : graph[start][end]})
    return graph_t
    
def union(graph, graph_t):
    for node in graph_t:
        if node in graph:
            if isinstance(graph[node], dict) and isinstance(graph_t[node], dict):
                union(graph[node], graph_t[node])
            elif graph[node] == graph_t[node]:
                pass
        else:
            graph[node] = graph_t[node]
    return graph

paths = {nodes: 'inf' for nodes in graph.keys()}
visited = []
def bellman_ford(graph, node, visited):
    visited.append(node)
    print(paths)
    for i in range(len(nodes)):
        for start in graph.keys():
            for end in graph[start]:
                if end not in visited:
                    try:
                        paths[end] = paths[node] + graph[node][end]
                        bellman_ford(graph, end, visited)
                    except KeyError:
                        pass
  
graph_t = transpose(graph)
graph = union(graph, graph_t)
print(graph)
node = 'c'
paths[node] = 0
bellman_ford(graph, 'c', visited)



'''
    Kruskal's algorithm finds a minimum spanning forest of an undirected edge-weighted graph.
'''
from collections import defaultdict

graph = {
    'a' : {'d' : 15, 'f' : 4, 'i' : 11},
    'b' : {'g' : 3, 'j' : 3},
    'c' : {'e' : 11, 'h' : 3},
    'd' : {'f' : 17, 'j' : 19},
    'e' : {'g' : 10},
    'f' : {'h' : 6, 'j' : 16},
    'g' : {'j' : 18},
    'h' : {'i' : 1, 'j' : 11},
    'i' : {},
    'j' : {}
}
nodes = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
weight = []
def create_graph(graph):
    for start in graph.keys():
        for end in graph[start]:
            weight.append(graph[start][end])
            graph_sorted = dict.fromkeys(sorted(weight), [])
    return graph_sorted
    
graph_sorted = {}
def sort(graph, graph_sorted):
    for start in graph:
        for end in graph[start]:
            if len(graph_sorted[graph[start][end]]) == 0:
                graph_sorted.update({graph[start][end] : [[start, end]]})
            else:
                graph_sorted[graph[start][end]].append([start, end])
    return graph_sorted
    
adjacency_lists = {}
def create_lists(graph):
    for i in range(len(nodes)):
        adjacency_lists.update({i + 1: [nodes[i]]})
    return adjacency_lists
    
def get_key(val, dict):
    for key, value in dict.items():
        for i in value:
            if i == val:
                return key

def Kruskal(graph_sorted, adjacency_lists):
    for weight in graph_sorted.keys():
        for i in range(len(graph_sorted[weight])):
            key = get_key(graph_sorted[weight][i][0], adjacency_lists)
            if graph_sorted[weight][i][1] not in adjacency_lists[key]:
                key1 = get_key(graph_sorted[weight][i][1], adjacency_lists)
                adjacency_lists[key] += adjacency_lists[key1]
                if len(adjacency_lists[key1]) == 1:
                    adjacency_lists.pop(key1)
                print(f"{weight} - {graph_sorted[weight][i]}")
                
graph_sorted = create_graph(graph)
graph_sorted = sort(graph, graph_sorted)
adjacency_lists = create_lists(graph)
print(graph_sorted)
print(adjacency_lists)
Kruskal(graph_sorted, adjacency_lists)
print('\n')



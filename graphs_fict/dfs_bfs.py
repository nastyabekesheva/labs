graph = [
    [0, 1, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 1],
    [0, 1, 0, 1, 1],
    [1, 1, 0, 0, 1]
]
visited = set()
stack = []
#visited2 = set()
queue = []
neighbour = []
def dfs(visited, graph, node):
    if node not in visited:
        visited.add(node)
        print(f"Node : {node}")
        for i in range(len(graph)):
            if graph[i][node] == 1 and graph[i][node] not in visited:
                stack.insert(0, i)
        print(f"Stack : {stack}")
        for neighbour in stack:
            try:
                stack.remove(neighbour)
                dfs(visited, graph, neighbour)
            except ValueError as ve:
                dfs(visited, graph, neighbour)
                
def bfs(visited, graph, node):
    if node not in visited:
        visited.add(node)
        queue.append(node)
        
        while queue:
            m = queue.pop(0)
            print(f"Node : {m}")
            
            for i in range(len(graph)):
                if graph[i][m] == 1 and i != m:
                    neighbour.append(i)
            for node in neighbour:
              if node not in visited and node not in queue:
                visited.add(node)
                queue.append(node)
            print(f"Queue : {queue}")



def main():
    print("DFS :")
    dfs(visited, graph, 0)
    visited.clear()
    print("\n")
    print("BFS :")
    bfs(visited, graph, 0)
    
main()

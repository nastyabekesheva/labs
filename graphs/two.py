'''
    A programm to check whether graph is connected or not.
    Using Warshall's algorithm to build adjacency matrix.
'''
graph = {
    'a' : ['b', 'f'],
    'b' : ['d'],
    'c' : ['d'],
    'd' : [],
    'e' : ['f'],
    'f' : []
}

nodes = ['a', 'b', 'c', 'd', 'e', 'f']
n = len(nodes)

def zero_matrix(n):
    matrix = [[0 for x in range(n)] for y in range(n)]
    return matrix

def get_matrix(graph, nodes,  n):
    matrix = zero_matrix(n)
    
    for i in range(n):
        for j in range(n):
            if nodes[j] in graph[nodes[i]]:
                matrix[i][j] = 1
                matrix[j][i] = 1
                
    for i in matrix:
        print(*i)
                
    return matrix
        
def warshall(matrix):
    warshall_matrix = [i[:] for i in matrix]
    for k in range(len(nodes)):
        for i in range(len(nodes)):
            for j in range(len(nodes)):
                warshall_matrix[i][j] = warshall_matrix[i][j] or (warshall_matrix[i][k] and warshall_matrix[k][j])
            
        for i in warshall_matrix:
            print(*i)
        print('\n')
        
    for i in range(len(nodes)):
        warshall_matrix[i][i] = 1
        
    return warshall_matrix

def get_connection(warshall_matrix):
    if 0 in warshall_matrix:
        print("The graph is not connected")
    else:
        print("The graph is connected")

print("Innitial matrix:\n")
matrix = get_matrix(graph, nodes,  n)
print("\n")
print("Adjacency matrix after using Warshall's algorithm:\n")
warshall_matrix =  warshall(matrix)
print("\n")
get_connection(warshall_matrix)





'''
    Theorem(about power of matrix of adjacency):
        Raising an adjacency matrix 𝐴 of simple graph 𝐺 to the 𝑛-th power gives the number of 𝑛-length
        walks between two vertices 𝑣𝑖, 𝑣𝑗 of 𝐺 in the resulting matrix.
'''


graph = {
    'a' : ['b', 'c', 'e'],
    'b' : ['c', 'd', 'f'],
    'c' : ['d'],
    'd' : ['f'],
    'e' : [],
    'f' : []
}

nodes = ['a', 'b', 'c', 'd', 'e', 'f']
n = len(nodes)

def zero_matrix(n):
    matrix = [[0 for x in range(n)] for y in range(n)]
    return matrix

def get_matrix(graph, nodes, n):
    matrix = zero_matrix(n)
    
    for i in range(n):
        for j in range(n):
            if nodes[j] in graph[nodes[i]]:
                matrix[i][j] = 1
                matrix[j][i] = 1
                
    for i in matrix:
        print(*i)
                
    return matrix
    
def power(matrix1, matrix2, k):
    while k > 1:
        result = zero_matrix(n)
        for i in range(len(nodes)):
            for j in range(len(nodes)):
                for l in range(len(nodes)):
                    result[i][j] += matrix1[i][l]*matrix2[l][j]

        for i in result:
            print(*i)
        print('\n')
        
        if k == 2:
            amount_of_walks ('d', 'c', result, nodes)
        
        return power(matrix, result, k - 1)
            
def amount_of_walks(a, b, matrix, nodes):
    i = nodes.index(a)
    j = nodes.index(b)
    print((f"Amount of ways between {a} and {b} : " + str(matrix[i][j])))


matrix = get_matrix(graph, nodes, n)
print('\n')
k = 6# length of ways
power(matrix, matrix, k)


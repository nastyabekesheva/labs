graph = [
    [0, 1, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 1],
    [0, 1, 0, 1, 1],
    [1, 1, 0, 0, 1]
]

def check_sym(matrix):
    for i in range(len(graph)):
        for j in range(len(graph)):
            if matrix[i][j] != matrix[j][i]:
                return False
    return True
    
def main():
    if check_sym(graph) == False:
        print("It's a digraph")
    elif check_sym(graph) == True:
        print("It's not a digraph")

main()


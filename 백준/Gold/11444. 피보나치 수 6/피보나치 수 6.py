n = int(input())

def matrix_multiplication(A, B):
    C = [[0]*2 for _ in range(2)]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                C[i][j] += A[i][k] * B[k][j]
            C[i][j] %= 1000000007
    return C

def matrix_pow(n):
    if n == 1:
        return A
    if n & 1:
        x = matrix_pow(n-1)
        return matrix_multiplication(x, A)
    else:
        x = matrix_pow(n//2)
        return matrix_multiplication(x, x)

A = [[1, 1], [1, 0]]
if n == 0      : print(0)
elif n in {1,2}: print(1)
else           : print(matrix_pow(n-1)[0][0])
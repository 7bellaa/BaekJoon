import sys
input = sys.stdin.readline

def matrix_multiplication(A,B):
    n = len(A)
    C = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
            C[i][j] %= 1000
    return C

def pow_matrix(n, arr):
    if n == 1:
        x = arr
    else:
        x = pow_matrix(n//2, arr)
        x = matrix_multiplication(x,x)
        if n & 1:
            x = matrix_multiplication(x,arr)
    for i in range(len(x)):
        for j in range(len(x)):
            x[i][j] %= 1000
    return x

n, b = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
for i in pow_matrix(b, arr):
    print(*i)
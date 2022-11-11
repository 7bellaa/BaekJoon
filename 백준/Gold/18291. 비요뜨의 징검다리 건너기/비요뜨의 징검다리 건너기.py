import sys
input = sys.stdin.readline

def fpow(a, n, c):
    if n == 1: return a % c
    else:
        x = fpow(a, n//2, c)
        if n & 1:
            return ((x%c) * (x%c) * (a%c)) % c
        else:
            return ((x%c) * (x%c)) % c

T = int(input())
c = 1000000007
for _ in range(T):
    n = int(input())
    if n > 2: print(fpow(2, n-2, c))
    else: print(1)
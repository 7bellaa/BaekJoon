import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    if n > 2: print(pow(2, n-2, 1000000007))
    else: print(1)
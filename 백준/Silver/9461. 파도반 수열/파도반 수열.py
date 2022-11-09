import sys
input = sys.stdin.readline
n = int(input())
a = [int(input()) for _ in range(n)]
dp = [0,1,1,1,2,2,3] + [0] * max(a)

def f(n):
    if dp[n]:
        return dp[n]
    else:
        dp[n] = f(n-1) + f(n-5)
        return dp[n]

for i in a: print(f(i))
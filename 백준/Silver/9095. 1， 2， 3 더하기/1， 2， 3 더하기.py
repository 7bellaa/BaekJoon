import sys
input = sys.stdin.readline
T = int(input())
dp = [0,1,2,4,7,13,24,44,81,149,274] # dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
for _ in range(T): print(dp[int(input())])
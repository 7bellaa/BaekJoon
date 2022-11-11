import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
a.sort()
dp = [a[0]]
for i in range(1,n):
    dp.append(a[i] + dp[i-1])
print(sum(dp))
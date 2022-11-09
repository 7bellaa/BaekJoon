import sys
from heapq import *
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
tmp = list(map(int, input().split()))
b = []
for i in tmp: heappush(b,i)
a.sort(reverse=True)
ans = 0
for i in a:
    ans += i * heappop(b)
print(ans)
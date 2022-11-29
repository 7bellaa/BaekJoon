import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

cnt = 0
end = n - 1
for start in range(n):
    if start >= end: break
    if a[start] + a[end] >= m:
        cnt += 1
        end -= 1

print(cnt)
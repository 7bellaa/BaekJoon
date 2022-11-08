import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
b = a[:]
b.sort()
d = {}
idx = -1
for i in b:
    if i not in d:
        idx += 1
        d[i] = idx

a = list(map(lambda x: d[x], a))
print(*a)
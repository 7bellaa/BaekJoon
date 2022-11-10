import sys
input = sys.stdin.readline
n, m = map(int, input().split())
root = list(range(n+1))
rank = [0] * (n+1)

def find(x):
    if root[x] == x: return x
    root[x] = find(root[x])
    return root[x]

def merge(x,y):
    x = find(x)
    y = find(y)
    
    if x == y: return
    if rank[x] < rank[y]:
        root[x] = y
    else:
        root[y] = x
    if rank[x] == rank[y]: x += 1

for _ in range(m):
    a = list(map(int, input().split()))
    if a[0] == 0:
        merge(a[1],a[2])
    else:
        if find(a[1]) == find(a[2]): print('YES')
        else: print('NO')
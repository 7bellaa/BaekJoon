import sys
input = sys.stdin.readline
r, g, b = 0, 0, 0
for _ in range(int(input())):
    x, y, z = map(int,input().split())
    r, g, b = min(g,b) + x, min(r,b) + y, min(r,g) + z
print(min(r,g,b))
import sys
input = sys.stdin.readline

d = [0] * 30
def f(n):
    if n == 0 or n == 1:
        return 1
    if d[n]:
        return d[n]
    else:
        d[n] = f(n-1) * n
        return d[n]

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    if n == m:
        print(1)
        continue
    else:
        print(f(m)//(f(n)*f(m-n)))
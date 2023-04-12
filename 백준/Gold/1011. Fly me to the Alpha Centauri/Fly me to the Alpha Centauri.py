import sys
input = sys.stdin.readline
n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    a = b - a
    cmp, i = 0, 0
    while(cmp < a):
        cmp += i // 2 + 1
        i += 1
    print(i)
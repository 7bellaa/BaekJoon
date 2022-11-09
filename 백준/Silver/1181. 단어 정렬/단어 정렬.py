import sys
input = sys.stdin.readline
n = int(input())
a = list(set([input().strip() for _ in range(n)]))
a.sort()
a.sort(key=len)
print('\n'.join(a))
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
x = int(input())
a.sort()
start, end = 0, n-1
cnt = 0
while(start < end):
    if a[start] + a[end] > x: end -= 1
    elif a[start] + a[end] < x: start += 1
    elif a[start] + a[end] == x:
        cnt += 1
        start += 1
        end -= 1
print(cnt)
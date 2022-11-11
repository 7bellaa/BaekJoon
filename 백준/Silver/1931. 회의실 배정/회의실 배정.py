import sys
input = sys.stdin.readline
n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
a.sort(key=lambda x: x[0])
a.sort(key=lambda x: x[1])
time, cnt = 0, 0
for i in a:
    if i[0] >= time:
        cnt += 1
        time = i[1]
print(cnt)
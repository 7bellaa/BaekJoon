import sys
input = sys.stdin.readline

n, s = map(int, input().split())
a = []
for _ in range(n):
    tmp = int(input())
    if tmp < s: a.append(tmp)
a.sort()
i, j = 0, len(a)-1
cnt = 0
n = len(a)
while(1):
    if i == j: break
    if a[i] + a[j] > s:
        j -= 1
    else:
        cnt += j-i
        i += 1

print(cnt)
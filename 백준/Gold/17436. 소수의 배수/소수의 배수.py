import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))
ans = 0

for i in range(1, 2**n):
    div = 1
    cnt = 0
    for j in range(n):
        if i & (1 << j):
            cnt += 1
            div *= a[j]

    if cnt & 1:
        ans += m // div
    else:
        ans -= m // div

print(ans)
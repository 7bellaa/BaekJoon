import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = [input() for _ in range(n)]
ans = ''
cnt = 0
for i in range(m):
    d = dict(zip("ACGT", [0,0,0,0]))
    for j in range(n):
        d[a[j][i]] += 1
    tmp = max(d, key=d.get)
    cnt += sum(d.values()) - d[tmp]
    ans += tmp
print(ans)
print(cnt)
n = int(input())
a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))

ans, cmp = 0, 1000000001

for l,m in zip(a1,a2):
    if cmp > m: cmp = m
    ans += cmp * l
print(ans)
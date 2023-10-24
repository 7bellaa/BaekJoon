n, k = map(int, input().split())
nk = n * k

factor = []
if n % 2 == 0: factor.append(2)
while n % 2 == 0: n //= 2

for i in range(3, 10000000, 2):
    if n < i: break
    if n % i: continue
    factor.append(i)
    while n % i == 0: n //= i
if n > 1: factor.append(n)

ans = nk * (nk + 1) // 2
size = len(factor)

def solve(cur, cnt, end):
    vis = [0] * size

    def dfs(prev, cur, cnt, end):
        global ans
        if cnt == end:
            if cnt & 1:
                ans -= (cur + nk) * nk // cur // 2;
                return
            else:
                ans += (cur + nk) * nk // cur // 2;
                return

        for i in range(cnt, size):
            if vis[i] or prev >= factor[i]: continue
            vis[i] = 1
            dfs(factor[i], cur * factor[i], cnt+1, end)
            vis[i] = 0
    
    dfs(1, cur, cnt, end)

for i in range(1, size+1):
    solve(1, 0, i)

print(ans)
n, m = map(int, input().split())
vis = [0] * (n+1)
ans = []

def f(x):
    global vis, ans

    if x == m:
        print(*ans)
        return
    
    for i in range(1, n+1):
        if not vis[i]:
            vis[i] = 1
            ans.append(i)
            f(x+1)
            vis[i] = 0
            ans.pop()

f(0)
n, m = map(int, input().split())
a = []

def solve(x):
    global a
    if x == m:
        print(*a)
        a.pop()
        return

    for i in range(1,n+1):
        if i not in a:
            a.append(i)
            solve(x+1)

    if x != 0: a.pop()

solve(0)
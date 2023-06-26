def solve():        
    w, h, L = map(int, input().split())
    ans = 0

    def solve_1(x,r):
        y = int((r**2 - x**2)**0.5)
        return y
    
    for i in range(-L, 1):
        ans += solve_1(i,L)*2 + 1
    for i in range(1,L+1):
        ans += solve_1(i,L) + 1

    ans -= h if L > h else L
    ans -= w if L > w else L
    ans -= 1

    r1, r2 = L-h, L-w
    if r1 <= 0 and r2 <= 0:
        return ans

    elif r1 > 0 and r2 <= 0:
        for i in range(1, r1):
            ans += solve_1(i,r1)
        return ans
    
    elif r1 <= 0 and r2 > 0:
        for i in range(1, r2):
            ans += solve_1(i,r2)
        return ans
    
    else:
        if L <= w+h:
            for i in range(1, r1):
                ans += solve_1(i,r1)
            for i in range(1, r2):
                ans += solve_1(i,r2)
            return ans
        
        else:
            for i in range(1, w):
                ans += solve_1(i,r1)
            for i in range(L-w-h+1, L-w):
                ans += solve_1(i,r2)
            for i in range(w, r1+1):
                ans += max(solve_1(i,r1)+h, solve_1(i-w,r2))
            return ans - h

print(solve())
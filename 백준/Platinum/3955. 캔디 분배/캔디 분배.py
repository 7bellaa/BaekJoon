import sys, math
input = sys.stdin.readline

def solve(a,b):
    if b == 1:
        if a >= 1_000_000_000: print("IMPOSSIBLE")
        else: print(a+1)
        return
    
    v = [(a,a//b,b,a%b)]
    n = 1
    while (v[-1][3]):
        ta, tb = v[-1][2], v[-1][3]
        v.append((ta,ta//tb,tb,ta%tb))
        n += 1
    if v[-1][2] != 1:
        print("IMPOSSIBLE")
        return
    
    xy = [(1,0), (0,1)]
    for i in range(n):
        x1, y1, x2, y2 = xy[i][0], xy[i][1], xy[i+1][0], xy[i+1][1]
        x3 = x1 - (x2*v[i][1])
        y3 = y1 - (y2*v[i][1])
        xy.append((x3,y3))
    
    if xy[-2][1] > 0:
        tx, ty = xy[-2][0], xy[-2][1]
    else:
        tx = xy[-3][0] - (v[-2][2]-v[-1][2]) * xy[-2][0]
        ty = xy[-3][1] - (v[-2][2]-v[-1][2]) * xy[-2][1]

    ty //= math.gcd(tx,ty)
    if ty > 1_000_000_000:
        print("IMPOSSIBLE")
    else:
        print(ty)

n = int(input())
for _ in range(n):
    a,b = map(int, input().split())
    solve(a,b)
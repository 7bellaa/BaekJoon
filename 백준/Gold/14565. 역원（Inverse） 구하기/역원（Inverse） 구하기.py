def modular_inverse(n, a):
    if a == 1:
        return 1

    v = [(n, n//a, a, n%a)]
    cnt = 1
    while v[-1][3]:
        tn, ta = v[-1][2], v[-1][3]
        v.append((tn, tn//ta, ta, tn%ta))
        cnt += 1

    if v[-1][2] != 1:
        return -1

    y = [0, 1]
    for i in range(cnt-1):
        y.append(y[i] - y[i+1]*v[i][1])
    
    res = y[-1]
    if res < 0:
        res = y[-2] - (v[-2][2]-v[-1][2]) * y[-1]
    return res if res < n else -1

n, a = map(int, input().split())
print(n-a, modular_inverse(n,a))
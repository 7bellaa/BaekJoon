def fpow(a, n, c):
    if n == 1: return a % c
    else:
        x = fpow(a, n//2, c)
        if n & 1:
            return ((x%c) * (x%c) * (a%c)) % c
        else:
            return ((x%c) * (x%c)) % c

a, b, c = map(int, input().split())
print(fpow(a,b,c))
import sys
input = sys.stdin.readline

GCD_MAX = 6666667
primes = list(range(GCD_MAX))
for i in range(2, GCD_MAX):
    if primes[i] == i:
        for j in range(i*2, GCD_MAX, i):
            if primes[j] == j: primes[j] = i

def GCD(a,b):
    while b:
        a, b = b, a % b
    return a

def solve(a,b):
    if a % b == 0 or b % a == 0:
        return a,b
    if (a & 1) and (b & 1):
        return a,1,b
    elif not (a & 1) and not (b & 1):
        return a,2,b
    else:
        gcd = GCD(a,b)
        if gcd == 1:
            return a,a*b,b
        else:
            return a,primes[gcd],b

n = int(input())
for _ in range(n): print(*solve(*map(int, input().split())))
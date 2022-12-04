import sys
input = sys.stdin.readline
MAX_NUM = 1000001
isPrime = [1] * MAX_NUM
isPrime[0] = isPrime[1] = 0
primes = []
for i in range(2, MAX_NUM):
    if isPrime[i]:
        primes.append(i)
        for j in range(2*i, MAX_NUM, i):
            isPrime[j] = 0

while(1):
    n = int(input())
    if n == 0: break
    idx = 1
    while(1):
        mp = primes[idx]
        if isPrime[n-mp]:
            print(f"{n} = {mp} + {n-mp}")
            break
        idx += 1
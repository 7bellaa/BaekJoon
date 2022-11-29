MAX_P = 1000000
prime = [1] * MAX_P
prime[0] = prime[1] = 0
for i in range(MAX_P):
    if prime[i]:
        for j in range(2*i, MAX_P, i):
            prime[j] = 0

N = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(2, N+1):
    if prime[i]:
        for j in range(N-i+1):
            if prime[sum(a[j:j+i])]: cnt += 1

print(cnt)
import sys
input = sys.stdin.readline
n = int(input())
a = list(map(lambda x: int(x)&1, input().split()))
L, R = 0, 0
cnt1 = 0
for i,v in enumerate(a):
    if v:
        L += i
        R += n-i-1
        cnt1 += 1

print(min(L, R) - (cnt1-1)*cnt1//2)
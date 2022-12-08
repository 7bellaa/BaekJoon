import sys
input = sys.stdin.readline
DIV = 1_000_000_007

n = int(input())
a = list(map(int, input().split()))
s = [a[0]%DIV]
for i in range(1, n):
    s.append((s[i-1]%DIV + a[i]%DIV) % DIV)
ans = 0
for i in range(1, n):
    ans = (ans%DIV + ((s[i-1]%DIV) * (a[i]%DIV))%DIV) % DIV
print(ans)
import sys
input = sys.stdin.readline
n = int(input())
a = input().split()
b = list(map(lambda x: x[0], a))
c = list(map(lambda x: x[1], a))

d = [0] * 26
for i in range(n):
    x = ord(c[i]) - 65
    if not d[x]:
        a = set(b[:i]) | set(b[i+1:])
        if sorted(list(a))[0] <= c[i]: d[x] = 1

    x = ord(b[i]) - 65
    if not d[x]:
        a = set(c[:i]) | set(c[i+1:])
        if sorted(list(a))[0] <= b[i]: d[x] = 1

print(sum(d))
a = []
for i in range(26):
    if d[i]: a.append(chr(i+65))
print(*sorted(a))
import sys
from math import *
team = input()
n = int(input())

cnt = {}
for _ in range(n):
    tmp = sys.stdin.readline().rstrip()
    if tmp[0] in cnt: cnt[tmp[0]] += 1
    else: cnt[tmp[0]] = 1

tcnt = {}
for i in team:
    if i in tcnt: tcnt[i] += 1
    else: tcnt[i] = 1

ans = 1
for k in tcnt:
    try: ans *= comb(cnt[k], tcnt[k])
    except:
        print(0)
        sys.exit(0)
print(ans)
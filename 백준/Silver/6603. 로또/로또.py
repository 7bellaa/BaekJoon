import sys
from itertools import combinations

while(1):
    a = list(map(int, sys.stdin.readline().rstrip().split()))
    if a[0] == 0: break
    for i in combinations(a[1:], 6):
        print(*i)
    print()
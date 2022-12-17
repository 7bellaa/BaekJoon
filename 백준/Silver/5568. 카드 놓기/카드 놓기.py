from itertools import permutations
n = int(input())
k = int(input())
a = [input() for _ in range(n)]
s = set()
for i in permutations(a,k):
    s.add(''.join(i))
print(len(s))
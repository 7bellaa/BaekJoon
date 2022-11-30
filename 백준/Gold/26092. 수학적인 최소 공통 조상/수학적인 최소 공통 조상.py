def findParent(a):
    if a % 2 == 0: return a//2
    for i in range(3, int(a**0.5)+1, 2):
        if a % i == 0: return a//i
    return 1

def solve(a,b):
    if a == b: return a
    if a < b: a, b = b, a
    return solve(b, findParent(a))

a, b = map(int, input().split())
print(solve(a,b))
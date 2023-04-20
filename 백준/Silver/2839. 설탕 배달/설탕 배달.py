a = int(input())

if a == 4 or a == 7: ans = -1
else:
    q, r = a // 5, a % 5
    if   r == 0: ans = q
    elif r == 3 or r == 1: ans = q + 1
    elif r == 2 or r == 4: ans = q + 2
    else: ans = -1

print(ans)
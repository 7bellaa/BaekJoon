n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
for i,j in zip(sorted(a),sorted(b,reverse=True)):
    ans += i*j
print(ans)
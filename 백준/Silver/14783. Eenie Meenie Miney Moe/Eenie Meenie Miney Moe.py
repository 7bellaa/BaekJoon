from collections import deque
N, L = map(int, input().split())
a = list(map(int, input().split()))
b = deque(list(range(1,N+1)))
cnt = 0
while (1):
    for i in a:
        for _ in range(i-1):
            tmp = b.popleft()
            b.append(tmp)
        b.popleft()
        cnt += 1
        if cnt == N-1: break
    if cnt == N-1: break

print(b.pop())
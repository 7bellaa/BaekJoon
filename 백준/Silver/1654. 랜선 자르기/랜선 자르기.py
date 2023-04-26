import sys
k, n = map(int, sys.stdin.readline().split())
a = [*map(int, sys.stdin.readlines())]

ma, Ma = min(a), max(a)
start = 0
end = Ma

def isCheck(cm):
    if cm == 0: return True  # start = 0, end = 1 인 경우 ZeroDivisionError 발생.
    cnt = 0
    for i in a:
        if i >= cm: cnt += i // cm
    if cnt >= n: return True
    else: return False

while start <= end:
    mid = (start + end) // 2
    if isCheck(mid):
        ans = mid
        start = mid + 1
    else:
        end = mid - 1

print(ans)
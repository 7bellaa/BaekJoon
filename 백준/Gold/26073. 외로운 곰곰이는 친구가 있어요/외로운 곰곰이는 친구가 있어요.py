from math import *
import sys
input = sys.stdin.readline

def isCheck(x, num):
    tmp = gcd(*num[1:])
    if x % tmp == 0: return 1
    else: return 0

N = int(input())
for _ in range(N):
    x, y = map(int, input().split())
    num = list(map(int, input().split()))
    if isCheck(x, num) and isCheck(y, num):
        print("Ta-da")
    else:
        print("Gave up")
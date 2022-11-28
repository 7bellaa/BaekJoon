from math import *
import sys
sys.setrecursionlimit(100000)

a,b,c = map(int, input().split())
epsilon = 1e-9

def F(x): return a*x + b*sin(x) - c
def f(x): return a + b*cos(x)

x1 = x2 = 0
while fabs(F(x1)) > epsilon:
    x2 = x1 - F(x1)/f(x1)
    x1 = x2
print(x1)
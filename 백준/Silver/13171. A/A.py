a = int(input())
b = int(input())
divisor = 1000000007

def fpow(a, n):
    if n == 1:
        return a
    else:
        x = fpow(a, n//2) % divisor
        if n & 1:
            return (x * x * a) % divisor
        else:
            return (x * x) % divisor

print(fpow(a,b))
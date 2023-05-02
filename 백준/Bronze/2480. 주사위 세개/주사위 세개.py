a,b,c = sorted(map(int, input().split()))

if a == b == c :
    print(10000 + 1000*a)
elif (a == b) or (b == c) :
    print(1000 + 100*b)
else :
    print(100*c)
a, b = map( int, input().split() )
c = int( input() )

m = c % 60
h = c // 60

a += h
b += m

if b >= 60 :
    b -= 60
    a += 1
if a >= 24 :
    a -= 24

print(a, b)


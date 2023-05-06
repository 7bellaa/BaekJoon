import math as m

H, V = map(float, input().split())
diag = m.sqrt(H**2 + V**2)
x = m.sqrt((V*H / (diag + H))**2 + H**2)
y = (V*H*diag) / (diag+H) / x
print(round(x/2, 2), round(y, 2))
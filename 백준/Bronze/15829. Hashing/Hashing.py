l = int(input())
s = input()
a = [ord(i)-96 for i in s]
for i in range(l): a[i] *= 31**i
print(sum(a)%1234567891)
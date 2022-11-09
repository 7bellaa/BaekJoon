m = [31,28,31,30,31,30,31,31,30,31,30,31]
d = ['MON','TUE','WED','THU','FRI','SAT','SUN']
a, b = map(int, input().split())
tmp = -1
for i in range(a-1):
    tmp += m[i]
tmp += b
print(d[tmp%7])
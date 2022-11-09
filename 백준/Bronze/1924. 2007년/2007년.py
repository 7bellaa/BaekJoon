m = [31,28,31,30,31,30,31,31,30,31,30,31]
d = ['SUN','MON','TUE','WED','THU','FRI','SAT']
a, b = map(int, input().split())
for i in range(a-1): b += m[i]
print(d[b%7])
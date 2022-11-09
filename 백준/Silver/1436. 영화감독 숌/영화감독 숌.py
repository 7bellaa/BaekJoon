n = int(input()) - 1
a = ['0666','1666','2666','3666','4666','5666'] + list(map(str, range(6660,6670))) + ['7666','8666','9666']
b = ['0666','1666','2666','3666','4666','5666'] + list(map(str, range(6600,6700))) + ['7666','8666','9666']
c = ['0666','1666','2666','3666','4666','5666'] + list(map(str, range(6000,7000))) + ['7666','8666','9666']

q1, r1 = n//3700, n%3700
if r1 < 1680:
    q2, r2 = r1//280, r1%280

    if r2 < 114:
        q3, r3 = r2//19, r2%19
        print(int(str(q1) + str(q2) + str(q3) + a[r3]))

    elif r2 < 223:
        q3, r3 = 6, r2-114
        print(int(str(q1) + str(q2) + str(q3) + b[r3]))
    
    else:
        r2 -= 90
        q3, r3 = r2//19, r2%19
        print(int(str(q1) + str(q2) + str(q3) + a[r3]))

elif r1 < 2860:
    q2, r2 = 6, r1-1680

    if r2 < 114:
        q3, r3 = r2//19, r2%19
        print(int(str(q1) + str(q2) + str(q3) + a[r3]))

    elif r2 < 1123:
        q3, r3 = 6, r2-114
        print(int(str(q1) + str(q2) + str(q3) + c[r3]))
    
    else:
        r2 -= 990
        q3, r3 = r2//19, r2%19
        print(int(str(q1) + str(q2) + str(q3) + a[r3]))

else:
    r1 -= 900
    q2, r2 = r1//280, r1%280

    if r2 < 114:
        q3, r3 = r2//19, r2%19
        print(int(str(q1) + str(q2) + str(q3) + a[r3]))

    elif r2 < 223:
        q3, r3 = 6, r2-114
        print(int(str(q1) + str(q2) + str(q3) + b[r3]))
    
    else:
        r2 -= 90
        q3, r3 = r2//19, r2%19
        print(int(str(q1) + str(q2) + str(q3) + a[r3]))
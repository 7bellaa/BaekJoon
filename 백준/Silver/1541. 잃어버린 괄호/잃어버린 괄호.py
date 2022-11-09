a = input()
b = '('
flag = True
for i in a:
    if i == '-':
        b += ')-('
    elif i == '0':
        if b[-1] not in {'+','('}:
            b += i
    else:
        b += i
b += ')'
print(eval(b))
from fractions import Fraction
n = input()
query = input().split()

def to3(q):
    stack = []
    ret = []
    depth = 0
    
    for i in q:
        if depth == 0 and len(stack):
            ret.append(stack)
            stack = []
        
        if i == '(':
            depth += 1
            stack.append(i)
        elif i == ')':
            depth -= 1
            stack.append(i)
        else:
            stack.append(i)
    
    if len(stack):
        ret.append(stack)
    
    if len(ret) != 3:
        print(-1)
        exit(0)

    return ret

def f(q):
    global stack
    if len(q) == 1: return int(q[0])

    if q[0] != '(' or q[-1] != ')':
        print(-1)
        exit(0)
    
    q = to3(q[1:-1])
    return f(q[0]) + Fraction(f(q[1]), f(q[2]))

ans = f(query)
print(ans.numerator, ans.denominator)
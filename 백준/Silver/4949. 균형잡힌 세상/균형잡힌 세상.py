import sys

def isCheck(s):
    stack = [0]   # [-1] 할때 오류 안나기 위해서
    for i in s:
        if i in {'[', '('}: stack.append(i)

        elif i == ']':
            if stack[-1] == '[': stack.pop()
            else               : return 'no'
        
        elif i == ')':
            if stack[-1] == '(': stack.pop()
            else               : return 'no'
    
    return 'yes' if stack == [0] else 'no'

while(1):
    s = sys.stdin.readline().rstrip()
    if s == '.': break
    print(isCheck(s))
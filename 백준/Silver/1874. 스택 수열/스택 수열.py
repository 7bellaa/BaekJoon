import sys

def main():
    n = int(input())
    stack, ans = [0], []
    b = list(range(n,0,-1))
    for _ in range(n):
        a = int(sys.stdin.readline())
        if a == stack[-1]:
            stack.pop()
            ans.append('-')

        elif a > stack[-1]:
            for _ in range(a - b[-1] + 1):       # while a in b 로 했더니 리스트에 in 연산을 하기 때문에 시간복잡도가 매우 커져서 시간 초과 뜸.
                stack.append(b.pop())
                ans.append('+')
            stack.pop()
            ans.append('-')
        
        else:
            print('NO')
            return

    print('\n'.join(ans))
    return

main()
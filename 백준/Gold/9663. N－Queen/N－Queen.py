def isCheck(x):
    for i in range(x):
        if board[x] == board[i] or x-i == abs(board[x] - board[i]): return False
    return True

def solve(x):
    global cnt
    if x == N:
        cnt += 1
        return

    for i in range(N):
        board[x] = i
        if isCheck(x): solve(x+1)

N = int(input())
board, cnt = [0] * N, 0
solve(0)
print(cnt)
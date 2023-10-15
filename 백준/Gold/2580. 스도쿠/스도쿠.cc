#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int board[N][N];
bool row[N][N+1];
bool col[N][N+1];
bool box[N][N+1];

int findBox(int x, int y) {
    return (x/3)*3 + (y/3);
}

bool solve(int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << board[i][j] << ' ';
            cout << '\n';
        }
        return true;
    }

    int x = cnt/N, y = cnt%N;
    if (board[x][y]) return solve(cnt+1);

    for (int i = 1; i <= N; i++) {
        if (row[x][i] || col[y][i] || box[findBox(x,y)][i]) continue;
        row[x][i] = col[y][i] = box[findBox(x,y)][i] = true;
        board[x][y] = i;
        if (solve(cnt+1)) return true;

        row[x][i] = col[y][i] = box[findBox(x,y)][i] = false;
        board[x][y] = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                row[i][board[i][j]] = col[j][board[i][j]] = box[findBox(i,j)][board[i][j]] = true;
            }
        }
    }

    solve(0);
}
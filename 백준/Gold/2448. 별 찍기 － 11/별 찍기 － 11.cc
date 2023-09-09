#include <bits/stdc++.h>
using namespace std;

const int X = 3 * 1024 + 1;
const int Y = 3 * 2048 + 1;
char board[X][Y];

void fill_star(int x, int y) {
    board[x][y] = '*';
    board[x+1][y-1] = board[x+1][y+1] = '*';
    for (int i = y-2; i <= y+2; i++) board[x+2][i] = '*';
}

void solve(int n, int x, int y) {
    if (n == 3) {
        fill_star(x, y);
        return;
    }
    n /= 2;
    solve(n, x, y);
    solve(n, x+n, y-n);
    solve(n, x+n, y+n);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    solve(n, 0, n-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2; j++) {
            if (board[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}
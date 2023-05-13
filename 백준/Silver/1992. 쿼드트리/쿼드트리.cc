#include <bits/stdc++.h>
using namespace std;

string board[64];
int N;

void solve(int n, int x, int y) {
    bool flag = true;
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (board[i][j] != board[x][y]) {flag = false; break;}
        }
    }
    if (flag) cout << board[x][y];
    else {
        n /= 2;
        cout << '(';
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) solve(n, x+n*i, y+n*j);
        }
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> board[i];
    solve(N, 0, 0);
}
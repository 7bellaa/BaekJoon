#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int N, M, a, b, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(&board[0][0], &board[100][101], -1);
    cin >> N >> M;
    while (M--) {
        cin >> a >> b >> c;
        if (board[a][b] == -1) board[a][b] = c;
        else board[a][b] = min(board[a][b], c);
    }
    for (int i = 1; i <= N; i++) board[i][i] = 0;

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][k] == -1 || board[k][j] == -1) continue;
                if (board[i][j] == -1) board[i][j] = board[i][k] + board[k][j]; 
                else board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == -1) cout << 0 << ' ';
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

const int N_MAX = numeric_limits<int>::max();
long long board[101][101];
long long N, M, a, b, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(&board[0][0], &board[100][101], N_MAX);
    cin >> N >> M;
    while (M--) {
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }
    for (int i = 1; i <= N; i++) board[i][i] = 0;

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][k] != N_MAX && board[k][j] != N_MAX) board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == N_MAX) cout << 0 << ' ';
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 간선이 없는 경우 0을 출력해야하는데 처리 안해서 틀림
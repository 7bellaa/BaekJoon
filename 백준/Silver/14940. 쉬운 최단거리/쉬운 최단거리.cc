#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    queue<pair<int, int>> Q;
    fill(&dist[0][0], &dist[1000][1001], -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {Q.push({i, j}); dist[i][j] = 0;}
        }
    }

    while (!Q.empty()) {
        auto [curX, curY] = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[curX][curY] + 1;
            Q.push({nx, ny});
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] != -1) cout << dist[i][j] << ' ';
            else if (board[i][j] == 0) cout << 0 << ' ';
            else cout << -1 << ' ';
        }
        cout << '\n';
    }
}
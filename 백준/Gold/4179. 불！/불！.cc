#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char board[1001][1001];
int dist[1001][1001];
int fire[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    queue<pair<int, int>> Q1, Q2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == '.') dist[i][j] = fire[i][j] = -1;
            if (board[i][j] == 'J') Q1.push({i, j});
            if (board[i][j] == 'F') Q2.push({i, j});
        }
    }

    while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (fire[nx][ny] >= 0) continue;

            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }

    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        if (cur.X == 0 || cur.X == N-1 || cur.Y == 0 || cur.Y == M-1) {cout << dist[cur.X][cur.Y] + 1; return 0;}

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] >= 0) continue;
            if (dist[cur.X][cur.Y]+1 >= fire[nx][ny] && fire[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}
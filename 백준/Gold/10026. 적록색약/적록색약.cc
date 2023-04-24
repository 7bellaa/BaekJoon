#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char board[101][101];
bool vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N;

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    vis[i][j] = 1;
    Q.push({i, j});
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int area() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            cnt++;
            bfs(i, j);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> board[i][j];
    }

    cout << area() << ' ';

    for (int i = 0; i < N; i++) fill(vis[i], vis[i]+N, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    cout << area();
}
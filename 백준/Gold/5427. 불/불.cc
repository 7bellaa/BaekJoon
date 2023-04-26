#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs() {
    int n, m; cin >> m >> n;
    char board[n][m];
    vector<vector<int>> fire(n, vector<int>(m, -1));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == '*') {fire[i][j] = 0; Q1.push({i, j});}
            if (board[i][j] == '@') {dist[i][j] = 0; Q2.push({i, j});}
        }
    }
    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;

            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {cout << dist[cur.X][cur.Y] + 1 << '\n'; return;}
            if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (dist[cur.X][cur.Y]+1 >= fire[nx][ny] && fire[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) bfs();
}
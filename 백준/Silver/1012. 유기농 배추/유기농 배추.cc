#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solve() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<int>> board(N, vector<int> (M, 0));
    vector<vector<int>> vis(N, vector<int> (M, 0));

    while (K--) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j] || vis[i][j]) continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (!board[nx][ny] || vis[nx][ny]) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) cout << solve() << '\n';
}
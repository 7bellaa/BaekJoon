#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[101][101];
bool vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M, K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) board[i][j] = 1;
        }
    }

    int cnt = 0;
    vector<int> widths;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j] && !vis[i][j]) {
                cnt++;
                int width = 1;
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});

                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny] || vis[nx][ny]) continue;

                        vis[nx][ny] = 1;
                        width++;
                        Q.push({nx, ny});
                    }
                }
                if (width) widths.push_back(width);
            }
        }
    }
    sort(widths.begin(), widths.end());
    cout << cnt << '\n';
    for (auto i : widths) cout << i << ' ';
}
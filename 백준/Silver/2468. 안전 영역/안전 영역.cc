#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[101][101];
bool vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int mx = 0, mn = 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
            mn = min(mn, board[i][j]);
        }
    }

    mx -= --mn;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) board[i][j] -= mn;
    }

    int ans = 1;
    while (mx--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {board[i][j]--; vis[i][j] = 0;}
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] <= 0 || vis[i][j]) continue;
                cnt++;
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});

                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] <= 0 || vis[nx][ny]) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
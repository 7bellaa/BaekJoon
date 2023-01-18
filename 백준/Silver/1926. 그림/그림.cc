#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cin >> board[i][j];
    }

    int cnt = 0, mx = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (vis[i][j] || !board[i][j]) continue;

            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});

            int width = 1;
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || !board[nx][ny]) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                    width++;
                }
            }
            mx = max(mx, width);
            cnt++;
        }
    }
    cout << cnt << '\n' << mx;
}
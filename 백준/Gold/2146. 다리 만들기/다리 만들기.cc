#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 101;
int board[N_MAX][N_MAX];
bool vis[N_MAX][N_MAX];
int dist[N_MAX][N_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void island() {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            idx++;

            while (!Q.empty()) {
                auto [curX, curY] = Q.front(); Q.pop();
                board[curX][curY] = idx;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];

                    if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
}

int solve() {
    fill(&dist[0][0], &dist[N_MAX-1][N_MAX], -1);
    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0) {Q.push({i, j}); dist[i][j] = 0;}
        }
    }

    int ans = 12345;
    while (!Q.empty()) {
        auto [curX, curY] = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if (OOB(nx, ny) || board[nx][ny] == board[curX][curY]) continue;
            if (board[nx][ny] != 0) {
                ans = min(ans, dist[nx][ny] + dist[curX][curY]);
            }
            else {
                board[nx][ny] = board[curX][curY];
                dist[nx][ny] = dist[curX][curY] + 1;
                Q.push({nx, ny});
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }
    island();
    cout << solve();
}
#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 301;
int board[N_MAX][N_MAX];
bool vis[N_MAX][N_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, cnt, day = -1;

bool bfs() {
    day++;
    cnt = 0;
    fill(&vis[0][0], &vis[N_MAX-1][N_MAX], 0);
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            cnt++;

            while (!Q.empty()) {
                auto [curX, curY] = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];

                    if (board[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            for (int dir = 0; dir < 4; dir++) {
                if (board[i][j] > 0 && board[i+dx[dir]][j+dy[dir]] == 0 && !vis[i+dx[dir]][j+dy[dir]]) board[i][j]--;
            }
        }
    }
    return (cnt != 0);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
    while (1) {
        if (bfs()) {
            if (cnt >= 2) {cout << day; break;}
        } else {
            cout << 0; break;
        }
    }
}
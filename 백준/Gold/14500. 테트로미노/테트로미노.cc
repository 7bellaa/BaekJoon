#include <bits/stdc++.h>
using namespace std;

int N, M, ans, board[501][501];
bool vis[501][501];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int curX, int curY, int dist, int sum) {
    if (dist == 4) {ans = max(ans, sum); return;}

    for (int dir = 0; dir < 4; dir++) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx, ny, dist+1, sum+board[nx][ny]);
        vis[nx][ny] = false;
    }
}

void remain(int curX, int curY) {
    for (int dir = 0; dir < 4; dir++) {
        bool flag = true;
        int sum = board[curX][curY];
        for (int i = 1; i <= 3; i++) {
            int ndir = (dir + i) % 4;
            int nx = curX + dx[ndir];
            int ny = curY + dy[ndir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {flag = false; break;}
            else sum += board[nx][ny];
        }
        if (flag) ans = max(ans, sum);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> board[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            vis[i][j] = false;
            remain(i, j);
        }
    }

    cout << ans;
}
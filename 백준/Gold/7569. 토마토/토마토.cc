#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int dz[6] = {1,0,0,-1,0,0};
int dx[6] = {0,1,0,0,-1,0};
int dy[6] = {0,0,1,0,0,-1};
int N, M, H;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    queue<tuple<int, int, int>> Q;
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 0) dist[i][j][k] = -1;
                if (board[i][j][k] == 1) Q.push({i, j, k});
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curZ, curX, curY) = cur; // 여기서 X Y Z 순서를 잘못써서 틀림.
        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (dist[nz][nx][ny] >= 0) continue;

            dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
            Q.push({nz, nx, ny});
        }
    }

    int mx = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (dist[i][j][k] == -1) {cout << -1; return 0;}
                mx = max(mx, dist[i][j][k]);
            }
        }
    }
    cout << mx;
}
// tie의 return value는 lvalue이다. 따라서
// tuple<int, int, int> t;
// t = {1,2,3};
// int a, b, c;
// tie(a, b, c) = t;

// 여기서 a, b, c의 값을 바꾸면 튜플 내부의 값도 바뀌게 된다.
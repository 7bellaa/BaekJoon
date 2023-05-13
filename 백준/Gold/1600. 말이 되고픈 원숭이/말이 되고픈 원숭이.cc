#include <bits/stdc++.h>
using namespace std;

int board[201][201];
int dist[201][201][31];
int dx[] = {-1,1,-1,1,-2,-2,2,2,1,0,-1,0};
int dy[] = {-2,-2,2,2,-1,1,-1,1,0,1,0,-1};
int N, M, K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> board[i][j];
    }
    fill(&dist[0][0][0], &dist[200][200][31], -1);

    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!Q.empty()) {
        auto [curX, curY, curC] = Q.front(); Q.pop();
        if (curX == N-1 && curY == M-1) {cout << dist[curX][curY][curC]; return 0;}
        for (int dir = 0; dir < 12; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nc = curC;
            if (dir < 8) {
                if (curC >= K) continue;
                else nc++;
            }
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 1 || dist[nx][ny][nc] != -1) continue;

            dist[nx][ny][nc] = dist[curX][curY][curC] + 1;
            Q.push({nx, ny, nc});
        }
    }
    cout << -1;
}
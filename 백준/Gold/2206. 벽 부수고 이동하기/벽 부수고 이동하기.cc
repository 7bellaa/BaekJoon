#include <bits/stdc++.h>
using namespace std;

string board[1001];
int dist[1001][1001][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    fill(&dist[0][0][0], &dist[1000][1000][2], -1);

    queue<tuple<int,int,int>> Q;
    dist[0][0][0] = 1;
    Q.push({0,0,0});

    while (!Q.empty()) {
        int curX, curY, broken;
        tie(curX, curY, broken) = Q.front(); Q.pop();
        if (curX == n-1 && curY == m-1) {cout << dist[curX][curY][broken]; return 0;}

        int nextdist = dist[curX][curY][broken] + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = nextdist;
                Q.push({nx, ny, broken});
            }
            else if (broken == 0 && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nextdist;
                Q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
}
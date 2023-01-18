#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;

string board[102];
int dist[102][102];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    queue<pair<int,int>> Q;
    Q.push({0,0});
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != '1' || dist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1]+1;
    return 0;
}
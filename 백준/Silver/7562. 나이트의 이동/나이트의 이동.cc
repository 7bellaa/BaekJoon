#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dist[301][301];
int dx[8] = {-1,1,-1,1,-2,-2,2,2};
int dy[8] = {-2,-2,2,2,-1,1,-1,1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2) {cout << 0 << '\n'; continue;}

        for (int i = 0; i < n; i++)
            fill(dist[i], dist[i]+n, -1);

        queue<pair<int, int>> Q;
        dist[x1][y1] = 0;
        Q.push({x1, y1});

        while (dist[x2][y2] == -1) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[x2][y2] << '\n';
    }
}
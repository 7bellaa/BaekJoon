#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[502];
vector<vector<int>> dist(502, vector<int>(502, -1));
vector<vector<int>> hp(502, vector<int>(502, -1));
vector<vector<int>> umbrella(502, vector<int>(502, -1));
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, H, D;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> H >> D;
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'S') {Q.push({i, j}); dist[i][j] = umbrella[i][j] = 0; hp[i][j] = H;}
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if (board[cur.X][cur.Y] == 'E') {cout << dist[cur.X][cur.Y]; return 0;}
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int nd = dist[cur.X][cur.Y] + 1;
            int nh = hp[cur.X][cur.Y];
            int nu = umbrella[cur.X][cur.Y];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (board[nx][ny] == 'U') nu = D;
            if (board[nx][ny] == '.' || board[nx][ny] == 'U') {
                if (nu > 0) nu--;
                else nh--;
            }

            if (nh <= 0) continue;

            if (nh + nu > hp[nx][ny] + umbrella[nx][ny]) {
                dist[nx][ny] = nd;
                hp[nx][ny] = nh;
                umbrella[nx][ny] = nu;
                Q.push({nx, ny});
            }
        }
    }
    cout << -1;
}
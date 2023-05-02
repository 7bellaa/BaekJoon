#include <bits/stdc++.h>
using namespace std;

char board[31][31][31];
int dist[31][31][31];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int R, C, L;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (cin >> L >> R >> C && L + R + C) {
        fill(&board[0][0][0], &board[30][30][31], '\0');
        fill(&dist[0][0][0], &dist[30][30][31], 0);
        queue<tuple<int, int, int>> Q;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string s; cin >> s;
                for (int k = 0; k < C; k++) {
                    board[j][k][i] = s[k];
                    if (s[k] == '.' || s[k] == 'E') dist[j][k][i] = -1;
                    else if (s[k] == 'S') Q.push({j, k, i});
                }
            }
        }

        bool flag = true;
        while (!Q.empty()) {
            int curX, curY, curZ;
            tie(curX, curY, curZ) = Q.front(); Q.pop();
            if (board[curX][curY][curZ] == 'E') {cout << "Escaped in " << dist[curX][curY][curZ] << " minute(s).\n"; flag = false; break;}

            for (int dir = 0; dir < 6; dir++) {
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dir];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
                if (dist[nx][ny][nz] != -1) continue;

                dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
                Q.push({nx, ny, nz});
            }
        }
        if (flag) cout << "Trapped!\n";
    }
}
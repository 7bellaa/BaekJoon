#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 601;

string board[N_MAX];
bool vis[N_MAX][N_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> board[i];
    fill(&vis[0][0], &vis[N_MAX-1][N_MAX], false);

    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'I') {Q.push({i, j}); vis[i][j] = true;}
        }
    }

    int cnt = 0;
    while (!Q.empty()) {
        auto [curX, curY] = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] || board[nx][ny] == 'X') continue;

            if (board[nx][ny] == 'P') cnt++;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    if (cnt) cout << cnt;
    else cout << "TT";
}
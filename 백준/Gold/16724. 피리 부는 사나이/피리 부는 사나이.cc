#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N_MAX = 1001;
char board[N_MAX][N_MAX];
int discovered[N_MAX][N_MAX];
bool finished[N_MAX][N_MAX];
map<char, pair<int, int>> dir = {{'D', {1,0}}, {'R', {0,1}}, {'U', {-1,0}}, {'L', {0,-1}}};
int n, m, node_order, cycle;

void dfs(int curX, int curY) {
    discovered[curX][curY] = node_order++;
    auto [dx, dy] = dir[board[curX][curY]];
    int nx = curX + dx;
    int ny = curY + dy;

    if (discovered[nx][ny] == -1) dfs(nx, ny);
    else if (!finished[nx][ny]) cycle++;
    finished[curX][curY] = true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
    fill(&discovered[0][0], &discovered[N_MAX-1][N_MAX], -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!finished[i][j]) dfs(i, j);
        }
    }
    cout << cycle;
}
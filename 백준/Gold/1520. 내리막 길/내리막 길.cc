#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, board[501][501], dp[501][501];

// (0, 0)에서 (x, y)까지 도달하는 경우의 수
int dfs(int x, int y) {
  if (x == 0 && y == 0)
    return 1;
  if (dp[x][y] != -1)
    return dp[x][y];

  dp[x][y] = 0;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] <= board[x][y])
      continue;
    dp[x][y] += dfs(nx, ny);
  }
  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }
  fill(&dp[0][0], &dp[500][501], -1);
  cout << dfs(n - 1, m - 1);
}
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int N_MAX = 52;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ans;
int block[N_MAX][N_MAX];

void fill_water(int h) {
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j])
        continue;
      vis[i][j] = true;
      if (block[i][j] >= h)
        continue;
      queue<pair<int, int>> Q;
      Q.push({i, j});

      bool is_leak = false;
      vector<pair<int, int>> path;
      while (!Q.empty()) {
        auto cur = Q.front();
        path.push_back(cur);
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            is_leak = true;
            continue;
          }
          if (vis[nx][ny])
            continue;

          vis[nx][ny] = true;
          if (block[nx][ny] >= h)
            continue;
          Q.push({nx, ny});
        }
      } // end of while (!Q.empty())

      if (is_leak)
        continue;
      for (auto [x, y] : path) {
        ans += h - block[x][y];
        block[x][y] = h;
      }
    } // end of for-loop(j)
  } // end of for-loop(i)
}

void init() {
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      block[i][j] = s[j] - '0';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  for (int i = 1; i < 10; i++)
    fill_water(i);
  cout << ans;
}
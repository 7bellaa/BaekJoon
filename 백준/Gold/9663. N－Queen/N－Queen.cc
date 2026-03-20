#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 15;

int n, col[N_MAX], diag1[2 * N_MAX], diag2[2 * N_MAX];

bool is_valid(int x, int y) {
  if (col[y] || diag1[n + x - y] || diag2[x + y])
    return false;
  return true;
}

int dfs(int x) {
  if (x == n)
    return 1;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!is_valid(x, i))
      continue;

    col[i] = true;
    diag1[n + x - i] = true;
    diag2[x + i] = true;

    ans += dfs(x + 1);

    col[i] = false;
    diag1[n + x - i] = false;
    diag2[x + i] = false;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cout << dfs(0);
}
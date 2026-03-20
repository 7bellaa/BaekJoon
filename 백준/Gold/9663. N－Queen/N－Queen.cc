#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 15;

int n, queen[N_MAX];

bool is_valid(int x, int y) {
  for (int i = 0; i < x; i++) {
    if (queen[i] == y)
      return false;
    if ((x - i) == abs(y - queen[i]))
      return false;
  }
  return true;
}

int dfs(int x) {
  if (x == n)
    return 1;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!is_valid(x, i))
      continue;

    queen[x] = i;
    ans += dfs(x + 1);
    queen[x] = -1;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  fill(&queen[0], &queen[n], -1);
  cout << dfs(0);
}
#include <bits/stdc++.h>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
int n, dp[501][501], prefix_sum[501];

int cost(int i, int j) { return prefix_sum[j] - prefix_sum[i - 1]; }

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> prefix_sum[i];
    prefix_sum[i] += prefix_sum[i - 1];
    dp[i][i] = 0;
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = INF;

      for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost(i, j));
    }
  }
  cout << dp[1][n] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
#include <bits/stdc++.h>
using namespace std;

int n, dp[501][501];
pair<int, int> arr[501];

int cost(int i, int k, int j) {
  return arr[i].first * arr[k].second * arr[j].second;
}

// dp[i][j] = min_{i <= k < j} {dp[i][k] + dp[k+1][j] + cost(i, j)}
void solve() {
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost(i, k, j));
      }
    }
  }
  cout << dp[0][n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    arr[i] = {t1, t2};
  }

  fill(&dp[0][0], &dp[500][501], 0x3f3f3f3f);
  for (int i = 0; i < n; i++)
    dp[i][i] = 0;
  solve();
}
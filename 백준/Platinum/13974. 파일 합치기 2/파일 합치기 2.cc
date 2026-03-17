#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N_MAX = 5001, INF = numeric_limits<long long>::max();
ll n, prefix_sum[N_MAX], dp[N_MAX][N_MAX], K[N_MAX][N_MAX];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> prefix_sum[i];
    prefix_sum[i] += prefix_sum[i - 1];
    dp[i][i] = 0;
    K[i][i] = i;
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = INF;

      int k_end = min((ll)j - 1, K[i + 1][j]);
      for (int k = K[i][j - 1]; k <= k_end; k++) {
        ll cand = dp[i][k] + dp[k + 1][j] + prefix_sum[j] - prefix_sum[i - 1];
        if (dp[i][j] > cand) {
          dp[i][j] = cand;
          K[i][j] = k;
        }
      }
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
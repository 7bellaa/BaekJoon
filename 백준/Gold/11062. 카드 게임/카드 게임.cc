#include <bits/stdc++.h>
using namespace std;

int N, arr[1001], prefix_sum[1001], dp[1001][1001];

int best_choice(int i, int j) {
  if (dp[i][j]) return dp[i][j];
  if (i == j) return dp[i][j] = arr[i];

  return dp[i][j] = (prefix_sum[j + 1] - prefix_sum[i]) -
                    min(best_choice(i + 1, j), best_choice(i, j - 1));
}

void init() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    // prefix_sum[i + 1] = sum(arr[0] ~ arr[i])
  }
  fill(&dp[0][0], &dp[1000][1001], 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    init();
    cout << best_choice(0, N - 1) << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

bool dp[81][16001];  // dp[i][w]: i명 뽑았을때 A_i의 합이 w가 될수있는가

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K, X;
  cin >> N >> K >> X;
  dp[0][0] = true;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;

    for (int k = K; k >= 1; k--) {
      for (int w = K * X; w >= a; w--) {
        if (dp[k - 1][w - a]) dp[k][w] = true;
      }
    }
  }

  int mx = 0;
  for (int w = 0; w <= 16000; w++) {
    if (!dp[K][w]) continue;
    if (abs((double)K * X / 2 - w) < abs((double)K * X / 2 - mx)) mx = w;
  }
  cout << mx * (K * X - mx);
}
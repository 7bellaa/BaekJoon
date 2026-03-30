#include <bits/stdc++.h>
using namespace std;

struct Item {
  int w, v;
};

vector<Item> items;
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  items.reserve(N * 14);

  for (int i = 0; i < N; i++) {
    int v, c, k;
    cin >> v >> c >> k;

    int b = 1;
    while (k >= b) {
      items.push_back({v * b, c * b});
      k -= b;
      b <<= 1;
    }

    if (k > 0) items.push_back({v * k, c * k});
  }

  vector<int> dp(M + 1, 0);
  for (const auto& i : items) {
    for (int j = M; j >= i.w; j--) {
      dp[j] = max(dp[j], dp[j - i.w] + i.v);
    }
  }
  cout << dp[M];
}
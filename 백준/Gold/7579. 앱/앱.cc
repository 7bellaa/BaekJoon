#include <bits/stdc++.h>
using namespace std;

int N, M, weight[101], cost[101], dp[10007];

void init() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> weight[i];
  for (int i = 0; i < N; i++) cin >> cost[i];
  fill(&dp[1], &dp[10007], -1); // dp[0] = 0;
}

// 가능한 weight로 dp를 돌리기엔 범위가 너무 큼. 반대로 생각하자
// dp[i] = cost를 i 이하로 쓰고 가능한 최대 메모리 확보량
void solve() {
  for (int i = 0; i < N; i++) {
    int w = weight[i], c = cost[i];
    for (int j = 10000; j >= 0; j--) {
      if (j < c || dp[j - c] == -1) continue;
      dp[j] = max(dp[j], dp[j - c] + w);
    }
  }

  for (int i = 0; i <= 10000; i++) {
    if (dp[i] >= M) {
      cout << i;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
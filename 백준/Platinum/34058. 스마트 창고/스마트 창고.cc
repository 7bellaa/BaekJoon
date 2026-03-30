#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 501;

int N, M;
int prefix_sum[N_MAX][N_MAX], ans[N_MAX][N_MAX][N_MAX];

void init() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> prefix_sum[i][j];
      prefix_sum[i][j] += prefix_sum[i][j - 1] + prefix_sum[i - 1][j] -
                          prefix_sum[i - 1][j - 1];
    }
  }
}

void solve() {
  for (int j1 = 1; j1 <= M; j1++) {
    for (int j2 = j1; j2 <= M; j2++) {
      vector<int> dp1(N_MAX), dp2(N_MAX + 1);

      // i행 포함하는 윗부분 최대구간합
      for (int i = 1; i <= N; i++) {
        int cur = prefix_sum[i][j2] - prefix_sum[i][j1 - 1] -
                  prefix_sum[i - 1][j2] + prefix_sum[i - 1][j1 - 1];
        dp1[i] = max(cur, dp1[i - 1] + cur);
      }

      // i행 포함하는 아랫부분 최대구간합
      for (int i = N; i >= 1; i--) {
        int cur = prefix_sum[i][j2] - prefix_sum[i][j1 - 1] -
                  prefix_sum[i - 1][j2] + prefix_sum[i - 1][j1 - 1];
        dp2[i] = max(cur, dp2[i + 1] + cur);
      }

      for (int r = 1; r <= N; r++) {
        int cur = prefix_sum[r][j2] - prefix_sum[r][j1 - 1] -
                  prefix_sum[r - 1][j2] + prefix_sum[r - 1][j1 - 1];
        ans[r][j1][j2] = dp1[r] + dp2[r] - cur;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    vector<int> mx_ans(M + 1, -0x3f3f3f3f);
    for (int j1 = 1; j1 <= M; j1++) {
      for (int j2 = j1; j2 <= M; j2++)
        mx_ans[j2] = max(mx_ans[j2], ans[i][j1][j2]);
      cout << *max_element(mx_ans.begin() + j1, mx_ans.end()) << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
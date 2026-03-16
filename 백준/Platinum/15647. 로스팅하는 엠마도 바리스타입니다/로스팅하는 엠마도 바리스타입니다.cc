#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N_MAX = 300001;

vector<pair<ll, ll>> graph[N_MAX];
ll N, dist_sum[N_MAX], child_num[N_MAX];

ll calc_dist_sum(ll cur, ll prev) {
  ll sum = 0, child = 0;

  for (auto [nx, d] : graph[cur]) {
    if (nx == prev)
      continue;
    sum += calc_dist_sum(nx, cur) + d * (child_num[nx] + 1);
    child += child_num[nx] + 1;
  }

  child_num[cur] = child;
  return sum;
}

void init() {
  int u, v, d;
  cin >> N;
  for (ll i = 1; i < N; i++) {
    cin >> u >> v >> d;
    graph[u].push_back({v, d});
    graph[v].push_back({u, d});
  }
}

void fill_dp(ll cur, ll prev) {
  for (auto [nx, d] : graph[cur]) {
    if (nx == prev)
      continue;
    dist_sum[nx] =
        dist_sum[cur] - d * (child_num[nx]) + d * (N - child_num[nx] - 2);
    fill_dp(nx, cur);
  }
}

void solve() {
  dist_sum[1] = calc_dist_sum(1, 0);
  fill_dp(1, 0);
  for (ll i = 1; i <= N; i++)
    cout << dist_sum[i] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
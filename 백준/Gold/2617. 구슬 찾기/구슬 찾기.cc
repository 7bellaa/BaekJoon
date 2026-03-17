#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100;

int N, M;
// heavy_graph: 나보다 무거운 애한테만 갈 수 있음
// light_graph: 나보다 가벼운 애한테만 갈 수 있음
vector<int> heavy_graph[N_MAX], light_graph[N_MAX];
int vis[N_MAX];

void init() {
  cin >> N >> M;
  int u, v;
  while (M--) {
    cin >> u >> v;
    heavy_graph[v].push_back(u);
    light_graph[u].push_back(v);
  }
}

int dfs(int cur, vector<int> *graph) {
  int cnt = 1;
  vis[cur] = true;
  for (int nx : graph[cur]) {
    if (vis[nx])
      continue;
    cnt += dfs(nx, graph);
  }
  return cnt;
}

void solve() {
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    fill(vis, vis + 100, false);
    int heavy = dfs(i, heavy_graph) - 1; // 자기 자신 제외

    fill(vis, vis + 100, false);
    int light = dfs(i, light_graph) - 1; // 자기 자신 제외

    if (heavy > (N / 2) || light > (N / 2))
      ans++;
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
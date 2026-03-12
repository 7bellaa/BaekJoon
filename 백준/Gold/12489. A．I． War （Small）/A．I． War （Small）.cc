#include <bits/stdc++.h>
using namespace std;

int p, w;
vector<vector<int>> graph;
vector<int> dist;

void dfs(int &max_threat, vector<int> &vis, int cur) {
  if (cur == 0) {
    set<int> s;
    for (int i : vis) {
      s.insert(i);
      for (int j : graph[i])
        s.insert(j);
    }
    max_threat = max(max_threat, (int)s.size());
    return;
  }

  for (int nx : graph[cur]) {
    if (dist[nx] != dist[cur] - 1)
      continue;
    vis.push_back(nx);
    dfs(max_threat, vis, nx);
    vis.pop_back();
  }
}

void init() {
  cin >> p >> w;
  graph = vector<vector<int>>(p, vector<int>());
  while (w--) {
    int u, v;
    char sep;
    cin >> u >> sep >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dist = vector<int>(p, -1);
}

pair<int, int> solve() {
  // bfs
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nx : graph[cur]) {
      if (dist[nx] != -1)
        continue;
      dist[nx] = dist[cur] + 1;
      q.push(nx);
    }
  }

  int max_threat = 0;
  vector<int> vis;
  dfs(max_threat, vis, 1);
  return {dist[1] - 1, max_threat - dist[1]};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    init();
    cout << "Case #" << i << ": ";
    auto [a, b] = solve();
    cout << a << ' ' << b << '\n';
  }
}
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// graph를 vector<int> graph[] 로 선언하고
// bool connected[401][401]를 만들어두면 set안쓰고 연결여부 O(1)에 체크 가능

int p, w;
vector<set<int>> graph;
vector<int> dist;
int dp[401][401];

void init() {
  cin >> p >> w;
  graph = vector<set<int>>(p, set<int>());
  dist = vector<int>(p, -1);
  fill(&dp[0][0], &dp[400][401], -1);
  int u, v;
  char sep;
  while (w--) {
    cin >> u >> sep >> v;
    graph[u].insert(v);
    graph[v].insert(u);
  }
}

pair<int, int> solve() {
  // bfs
  queue<int> Q;
  Q.push(0);
  dist[0] = 0;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int nx : graph[cur]) {
      if (dist[nx] != -1)
        continue;
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  // 초기값 dp[0][i] 채우기
  for (int nx : graph[0]) {
    int new_threat = 0;
    for (int nnx : graph[nx]) {
      if (nnx == 0)
        continue;
      if (graph[0].find(nnx) != graph[0].end())
        continue;
      new_threat++;
    }
    dp[0][nx] = graph[0].size() - 1 + new_threat;
  }

  // while (!Q.empty())로 평소처럼 bfs 돌리면 바로 전 정점은 알수있지만 그 전
  // 정점을 모름. 그래서 미리 구해둔 dist를 이용해 3중 for문으로 bfs 구현
  for (int d = 1; d < dist[1] - 1; d++) {
    for (int cur = 0; cur < p; cur++) {
      if (dist[cur] != d)
        continue;

      for (int prev : graph[cur]) {
        if (dist[prev] != d - 1)
          continue;

        for (int nx : graph[cur]) {
          if (dist[nx] != d + 1)
            continue;

          int new_threat = 0;
          for (int nnx : graph[nx]) {
            if (nnx == cur)
              continue;
            if (graph[cur].find(nnx) != graph[cur].end())
              continue;
            if (graph[prev].find(nnx) != graph[prev].end())
              continue;
            new_threat++;
          }
          dp[cur][nx] = max(dp[cur][nx], dp[prev][cur] - 1 + new_threat);
        } // for-loop (nx)
      } // for-loop (prev)
    } // for-loop (cur)
  } // for-loop (d)

  int max_threat = 0;
  for (int i : graph[1]) {
    if (dist[i] != dist[1] - 1)
      continue;
    for (int j : graph[i]) {
      if (dist[j] != dist[1] - 2)
        continue;
      max_threat = max(max_threat, dp[j][i]);
    }
  }
  // dist[1] == 1인 경우 바로 위의 for-loop(j) 에서 아무것도 하지 않음
  // 그래서 max_threat가 0을 리턴하게 됨 -> 예외 처리 필요
  if (dist[1] == 1)
    return {0, graph[0].size()};
  else
    return {dist[1] - 1, max_threat};
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
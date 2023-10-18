#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& vis, int cur, int& dist) {
    vis[cur] = ++dist;
    for (auto x : graph[cur]) {
        if (vis[x] == 0) dfs(graph, vis, x, dist);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, R, dist = 0;
    cin >> N >> M >> R;
    vector<vector<int>> graph(N+1);
    vector<int> vis(N+1, 0);
    while (M--) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto &e : graph) sort(e.begin(), e.end());

    dfs(graph, vis, R, dist);
    for (int i = 1; i <= N; i++) cout << vis[i] << '\n';
}
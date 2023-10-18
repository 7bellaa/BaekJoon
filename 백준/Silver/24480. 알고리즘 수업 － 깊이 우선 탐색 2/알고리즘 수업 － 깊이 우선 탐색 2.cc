#include <bits/stdc++.h>
using namespace std;

int N, M, R, a, b, cnt;
vector<vector<int>> graph;
vector<int> vis;

void dfs(int cur) {
    vis[cur] = ++cnt;
    for (auto i : graph[cur]) {
        if (vis[i] == 0) dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R;
    vis = vector<int>(N+1, 0);
    graph = vector<vector<int>>(N+1);

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (auto &i : graph) sort(i.begin(), i.end(), greater<int>());
    dfs(R);
    for (int i = 1; i <= N; i++) cout << vis[i] << '\n';
}
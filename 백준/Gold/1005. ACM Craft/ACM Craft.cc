#include <bits/stdc++.h>
using namespace std;

void solve() {
    int E, V; cin >> E >> V;
    vector<vector<int>> graph(E+1);
    vector<int> indegree(E+1, 0);
    vector<int> time(E+1);
    vector<int> result(E+1, 0);

    for (int i = 1; i <= E; i++)
        cin >> time[i];
    for (int i = 0; i < V; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    int W; cin >> W;

    queue<int> Q;
    for (int i = 1; i <= E; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
            result[i] = time[i];
        }
    }

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto i : graph[cur]) {
            indegree[i]--;
            result[i] = max(result[i], result[cur]+time[i]);
            if (indegree[i] == 0) Q.push(i);
        }
    }

    cout << result[W] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
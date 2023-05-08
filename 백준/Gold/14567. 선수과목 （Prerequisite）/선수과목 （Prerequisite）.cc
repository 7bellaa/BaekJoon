#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int E, V; cin >> E >> V;
    vector<vector<int>> graph(E+1);
    vector<int> indegree(E+1, 0);
    vector<int> dp(E+1, 1);

    for (int i = 0; i < V; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> Q;
    for (int i = 1; i <= E; i++) {
        if (indegree[i] == 0) Q.push(i);
    }

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i : graph[cur]) {
            indegree[i]--;
            dp[i] = dp[cur]+1;
            if (indegree[i] == 0) Q.push(i);
        }
    }
    for (int i = 1; i <= E; i++) cout << dp[i] << ' ';
}
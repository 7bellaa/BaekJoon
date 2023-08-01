#include <bits/stdc++.h>
using namespace std;

int n, m, t, graph[101], dist[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(dist, dist+101, -1);
    cin >> n >> m;
    while (n--) {
        cin >> t;
        cin >> graph[t];
    }
    while (m--) {
        cin >> t;
        cin >> graph[t];
    }

    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == 100) break;
        for (int i = 1; i <= 6; i++) {
            int nx = cur + i;
            if (graph[nx] != 0) nx = graph[nx];
            if (nx > 100 || dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << dist[100];
}
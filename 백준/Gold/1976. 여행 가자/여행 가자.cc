#include <bits/stdc++.h>
using namespace std;

int root[201];

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    root[y] = x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    iota(root, root+201, 0);
    vector<vector<int>> graph(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> graph[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (graph[i][j]) merge(i, j);
        }
    }

    vector<int> path(m);
    for (auto &i : path) cin >> i;
    int cmp = find(path[0]);
    for (auto i : path) {
        if (cmp != find(i)) {cout << "NO"; return 0;}
    }
    cout << "YES";
}
#include <bits/stdc++.h>
using namespace std;

int root[500001];

int find(int x) {
    if (x == root[x]) return x;
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
    iota(root, root+n+1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (find(a) == find(b)) {cout << i; return 0;} // root[a] == root[b]로 해서 틀림
        merge(a, b);
    }
    cout << 0;
}
#include <bits/stdc++.h>
using namespace std;

int root[300001];

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
    int n; cin >> n;
    if (n == 2) {cout << "1 2"; return 0;}
    iota(root, root+300001, 0);
    for (int i = 0; i < n-2; i++) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n ; j++) {
            if (find(i) != find(j)) {cout << i << ' ' << j; return 0;}
        }
    }
}
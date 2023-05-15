#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100001;
int root[N_MAX];
vector<int> military(1, 0);
int n, m, o, p, q;

int find(int x) {
    if (x == root[x]) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    root[y] = x;
    military[x] += military[y];
    military[y] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    iota(root, root+n+1, 0);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        military.push_back(t);
    }
    while (m--) {
        cin >> o >> p >> q;
        if (o == 1) merge(p, q);
        else {
            p = find(p);
            q = find(q);
            if (military[p] > military[q]) {
                military[p] -= military[q];
                military[q] = 0;
                root[q] = p;
            } else if (military[p] < military[q]) {
                military[q] -= military[p];
                military[p] = 0;
                root[p] = q;
            } else {
                root[p] = root[q] = military[p] = military[q] = 0;
            }
        }
    }
    sort(military.begin(), military.end());
    vector<int> ans;
    for (auto i : military) {
        if (i) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto i : ans) 
        cout << i << ' ';
}
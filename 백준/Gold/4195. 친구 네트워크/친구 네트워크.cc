#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& root, int x) {
    if (x == root[x]) return x;
    return root[x] = find(root, root[x]);
}

void merge(vector<int>& root, vector<int>& cardinality, int x, int y) {
    x = find(root, x);
    y = find(root, y);

    if (x == y) return;
    root[y] = x;
    cardinality[x] += cardinality[y];
}

void solve() {
    int n; cin >> n;
    vector<int> root(2*n);
    vector<int> cardinality(2*n, 1);
    iota(root.begin(), root.end(), 0);

    map<string, int> m;
    int id = 0;
    while (n--) {
        string s1, s2; cin >> s1 >> s2;
        if (m.find(s1) == m.end()) m[s1] = id++;
        if (m.find(s2) == m.end()) m[s2] = id++;

        merge(root, cardinality, m[s1], m[s2]);
        cout << cardinality[find(root, m[s1])] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    vector<bool> vis(n, false);
    for (auto &i : v) cin >> i;

    for (int i = 0; i < n; i++) {
        int cur = v[i];
        if (vis[cur] || vis[cur-1] || cur == 1) continue;
        auto it1 = v.begin() + i, it2 = find(v.begin(), v.end(), cur-1);
        if (it1 < it2) {
            vis[cur] = vis[cur-1] = true;
            iter_swap(it1, it2);
        }
    }
    for (auto i : v) cout << i << '\n';
}
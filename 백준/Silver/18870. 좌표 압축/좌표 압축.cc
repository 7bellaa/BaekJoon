#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    vector<int> v2(v);
    sort(v2.begin(), v2.end());
    int idx = 0;
    map<int, int> m;

    for (auto i : v2) {
        if (m.find(i) == m.end()) m[i] = idx++;
    }

    for (auto i : v) cout << m[i] << ' ';
}
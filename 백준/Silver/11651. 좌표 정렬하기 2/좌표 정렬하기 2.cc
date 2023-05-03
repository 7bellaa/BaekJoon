#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int, int>> v;
    int n; cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    for (auto i : v) {
        cout << i.second << ' ' << i.first << '\n';
    }
}
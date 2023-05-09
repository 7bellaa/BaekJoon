#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    queue<pair<int, bool>> Q;
    vector<int> importance(10, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        importance[t]++;
        if (i == m) Q.push({t, true});
        else Q.push({t, false});
    }

    int cnt = 0;
    while (1) {
        auto [x, y] = Q.front(); Q.pop();
        bool flag = true;
        for (int i = x+1; i <= 9; i++) {
            if (importance[i] > 0) {flag = false; break;}
        }
        if (flag) {
            cnt++;
            importance[x]--;
            if (y) return cnt;
        } else {
            Q.push({x, y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
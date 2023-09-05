#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N;
double res;

void dfs(const vector<pair<int, int>>& v, ll curX, ll curY, int idx, int cnt) {
    curX -= 2 * v[idx].first;
    curY -= 2 * v[idx].second;

    if (cnt == N/2) {
        res = min(res, sqrt(curX*curX + curY*curY));
    }

    for (int i = idx+1; i < N; i++) dfs(v, curX, curY, i, cnt+1);
}

void solve() {
    cin >> N;
    vector<pair<int, int>> v;

    ll sumX = 0, sumY = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
        sumX += a;
        sumY += b;
    }

    res = 40000000;
    for (int i = 0; i <= N/2; i++) dfs(v, sumX, sumY, i, 1);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    cout << fixed;
    cout.precision(15);
    while (T--) solve();
}
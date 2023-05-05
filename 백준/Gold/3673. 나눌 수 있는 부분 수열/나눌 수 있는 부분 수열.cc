#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1000001;
long long cnt[N_MAX];
int d, n, t;

void solve() {
    cin >> d >> n;
    vector<int> s(n+1);
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        s[i] = ((t%d) + s[i-1]) % d;
    }
    
    fill(cnt, cnt+N_MAX, 0);
    for (int i = 1; i <= n; i++) cnt[s[i]]++;
    long long ans = cnt[0];
    for (int i = 0; i < d; i++) {
        if (cnt[i] < 2) continue;
        ans += cnt[i] * (cnt[i]-1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin >> c;
    while (c--) {
        solve();
    }
}
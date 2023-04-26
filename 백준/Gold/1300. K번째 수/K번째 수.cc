#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll start = 1, end = n*n;
    ll mid, ans = n*n;
    while (start <= end) {
        mid = (start + end) / 2;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min(n, mid/i);
        }
        if (cnt >= k) {
            ans = min(ans, mid);
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    cout << ans;
}
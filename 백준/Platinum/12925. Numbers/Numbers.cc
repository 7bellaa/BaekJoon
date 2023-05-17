#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1000;

int solve() {
    int n; cin >> n;
    ll a = 0, b = 0, x = 3, y = 1;
    while (n > 1) {
        ll t1, t2;
        if (n & 1) {
            if (a == 0 && b == 0) {
                a = x; b = y;
            } else {
                t1 = ((a*x)%mod + (5*b*y)%mod) % mod;
                t2 = ((a*y)%mod + (b*x)%mod) % mod;
                a = t1, b = t2;
            }
        }
        t1 = ((x*x)%mod + (5*y*y)%mod) % mod;
        t2 = (2*x*y)%mod;
        x = t1; y = t2;
        n /= 2;
    }
    if (a == 0 && b == 0) return (2*x-1) % mod;
    else return ((((a*x)%mod + (5*b*y)%mod) % mod) * 2 - 1) % mod;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int a = solve();

        cout << "Case #" << i << ": ";
        if (a < 10) cout << "00" << a << '\n';
        else if (a < 100) cout << "0" << a << '\n';
        else cout << a << '\n';
    }
}
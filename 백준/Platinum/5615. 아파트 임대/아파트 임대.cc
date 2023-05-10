#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

vector<ll> n_miller {2, 7, 61};
ll t, n, cnt;

ll power(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    while (y) {
        if (y % 2) res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }
    return res;
}

bool miller(ll n, ll a) {
    if (n == 2 || n == 7 || n == 61) return true;
    if (a % n == 0) return false;
    ll k = n-1;
    while (1) {
        ll temp = power(a, k, n);
        if (temp == n-1) return true;
        if (k % 2) return (temp == 1 || temp == n-1);
        k /= 2;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> n;
        n = n * 2 + 1;

        for (ll a : n_miller) {
            if (!miller(n, a)) {cnt++; break;}
        }
    }
    cout << t - cnt;
}
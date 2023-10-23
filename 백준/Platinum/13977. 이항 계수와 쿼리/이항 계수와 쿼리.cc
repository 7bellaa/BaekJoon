#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int DIV = 1000000007;
vector<ll> factorial(1, 1);
ll N, K;

int power(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * n % DIV;
        n = n * n % DIV;
        k >>= 1;
    }
    return res;
}

void solve() {
    ll res = factorial[N] * power(factorial[N-K] * factorial[K] % DIV, DIV-2) % DIV;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 4000000; i++) {
        factorial.push_back(factorial.back() * i % DIV);
    }

    int t; cin >> t;
    while (t--) {
        cin >> N >> K;
        solve();
    }
}
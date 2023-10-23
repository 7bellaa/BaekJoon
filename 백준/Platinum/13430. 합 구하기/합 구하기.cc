#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int DIV = 1000000007;
ll N, K;

ll power(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * n % DIV;
        n = n * n % DIV;
        k >>= 1;
    }
    return res;
}

ll solve() {
    if (N == 1) return 1;
    ll a = 1, b = 1;
    for (ll i = N+K; i >= N; i--) a = a * i % DIV;
    for (ll i = 2; i <= K+1; i++) b = b * i % DIV;

    ll res = a * power(b, DIV-2) % DIV;
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;
    cout << solve();
}
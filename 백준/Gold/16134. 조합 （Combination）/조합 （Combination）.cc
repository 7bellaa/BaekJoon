#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int DIV = 1000000007;
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
    ll a = 1, b = 1;
    for (ll i = N; i >= N-K+1; i--) a = a * i % DIV;
    for (ll i = 1; i <= K; i++) b = b * i % DIV;

    ll res = a * power(b, DIV-2) % DIV;
    cout << res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    solve();
}
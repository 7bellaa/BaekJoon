#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int DIV = 1000000007;
ll M, N, S;
vector<ll> v;

ll power(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * n % DIV;
        n = n * n % DIV;
        k >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> N >> S;
        v.push_back(S * power(N, DIV-2) % DIV);
    }

    ll res = 0;
    for (auto i : v) res = (res + i) % DIV;
    cout << res;
}
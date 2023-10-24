#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int DIV = 1000000007;
ll N, K;
ll comb[52][52], v[52]; // comb[i][j] == comb(i, j) % DIV, v[i] == S(N, i)

ll power(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * n % DIV;
        n = n * n % DIV;
        k >>= 1;
    }
    return res;
}

void init() {
    for (int i = 0; i < 52; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % DIV;
        }
    }
    cin >> N >> K;
    v[0] = N;
}

void solve() {
    for (int i = 1; i <= K; i++) {
        v[i] = power(N+1, i+1) - 1;
        for (int j = 0; j < i; j++) v[i] = (v[i] - comb[i+1][j] * v[j]) % DIV;
        v[i] = v[i] * power(comb[i+1][i], DIV-2) % DIV;
        if (v[i] < 0) v[i] += DIV;
    }
    cout << v[K];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
}
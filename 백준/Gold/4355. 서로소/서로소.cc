#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isPrime[100001]; // if isPrime[n] == false -> n == prime
vector<int> primes;

ll power(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res *= n;
        n *= n;
        k >>= 1;
    }
    return res;
}

void init() {
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i < 100001; i++) {
        if (!isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j < 100001; j += i) isPrime[j] = true;
        }
    }
}

void solve(ll n) {
    map<ll, int> factor;
    for (auto i : primes) {
        if (i > n) break;
        if (n % i) continue;
        while (!(n % i)) {
            factor[i]++;
            n /= i;
        }
    }
    if (n > 1) factor[n] = 1;

    ll res = 1;
    for (auto [k, v] : factor) {
        res *= power(k, v-1) * (k - 1);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();

    while (1) {
        ll n; cin >> n;
        if (n == 1) cout << 0 << '\n';
        else if (n) solve(n);
        else break;
    }
}
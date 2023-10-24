#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N_MAX = 101;
bool isPrime[N_MAX];
ll sum[10001];
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
    for (int i = 2; i < N_MAX; i++) {
        if (!isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j < N_MAX; j += i) isPrime[j] = true;
        }
    }
}

ll phi(int n) {
    map<int, int> factor;
    for (auto i : primes) {
        if (n < i) break;
        if (n % i) continue;
        while (n % i == 0) {
            factor[i]++;
            n /= i;
        }
    }
    if (n > 1) factor[n]++;
    ll res = 1;

    for (auto [k, v]: factor) res *= power(k, v-1) * (k-1);
    return res;
}

void suffixSum() {
    sum[0] = 1;
    for (int i = 1; i < 10001; i++) sum[i] = sum[i-1] + phi(i);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    suffixSum();

    int t, k, n; cin >> t;
    while (t--) {
        cin >> k >> n;
        cout << k << ' ' << sum[n] << '\n';
    }
}
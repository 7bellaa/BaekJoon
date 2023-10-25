#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
179,181,191,193,197,199,211,223,227,229,233,239};

int power(int n, int k) {
    int ret = 1;
    while (k) {
        if (k & 1) ret *= n;
        n *= n;
        k >>= 1;
    }
    return ret;
}

map<int, int> factorize(int n) {
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
    return factor;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        auto m = factorize(i);
        int phi = 1;
        for (auto [k, v]: m) phi *= power(k, v-1) * (k-1);
        ans += phi;
    }
    cout << ans;
}
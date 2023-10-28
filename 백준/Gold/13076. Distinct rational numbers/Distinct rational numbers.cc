#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
vector<int> sum(2, 2);

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

void init() {
    for (int i = 2; i <= 10000; i++) {
        auto factor = factorize(i);
        int phi = 1;

        for (auto [k, v]: factor) phi *= power(k, v-1) * (k-1);
        sum.push_back(sum.back() + phi);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << sum[n] << '\n';
    }
}
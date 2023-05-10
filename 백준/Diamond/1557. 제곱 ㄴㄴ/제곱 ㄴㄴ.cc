#include <bits/stdc++.h>
using namespace std;

const int P_MAX = 45000;
vector<int> mu(P_MAX, -1);
vector<int> primes;
vector<bool> isPrime(P_MAX, true);

void init() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < P_MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j < P_MAX; j += i) isPrime[j] = false;
        }
    }

    mu[1] = 1;
    for (int i = 2; i < P_MAX; i++) {
        for (auto p : primes) {
            if (i * p >= P_MAX) break;
            if (i % p == 0) {mu[i*p] = 0; break;}
            mu[i*p] = mu[i] * mu[p];
        }
    }
}

bool isSquareFree(long long n) {
    for (auto i : primes) {
        if (n % (i*i) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int k; cin >> k;
    long long start = 1, end = k*2;
    while (start <= end) {
        long long mid = (start + end) / 2, cnt = 0;
        for (long long i = 1; i * i <= mid; i++) {
            cnt += mu[i] * (mid / (i*i));
        }
        if (cnt == k && isSquareFree(mid)) {cout << mid; break;}
        else if (cnt >= k) end = mid - 1;
        else start = mid + 1;
    }
}
#include <bits/stdc++.h>
using namespace std;

const int MAX_PRIME = 1000001;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> isPrime(MAX_PRIME, 1);
    vector<int> primes;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*2; j < MAX_PRIME; j += i) isPrime[j] = 0;
        }
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int start = 0, end = primes.size()-1, cnt = 0;
        while (start <= end) {
            int cmp = primes[start] + primes[end];

            if (cmp == n) {cnt++; start++; end--;}
            else if (cmp > n) end--;
            else start++;
        }
        cout << cnt << '\n';
    }
}
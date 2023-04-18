#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;

    vector<int> isPrime(N+1, 1);
    vector<int> primes;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < N+1; i++) {
        if (isPrime[i]) primes.push_back(i);
        for (int j = i*2; j < N+1; j += i) isPrime[j] = 0;
    }

    vector<int> sum(primes.size()+1, 0);
    for (int i = 1; i <= primes.size(); i++) {
        sum[i] = sum[i-1] + primes[i-1];
    }

    int start = 0, end = 0, cnt = 0;
    while (end++ < primes.size()) {
        while (sum[end] - sum[start] > N) start++;
        if (sum[end] - sum[start] == N) cnt++;
    }
    cout << cnt;
}
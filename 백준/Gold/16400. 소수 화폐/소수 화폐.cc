#include <bits/stdc++.h>
using namespace std;

const int MOD = 123456789;
bool isprime[40001];
vector<int> primes;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    fill(isprime, isprime+40001, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < 40001; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i*2; j < 40001; j += i) isprime[j] = 0;
        }
    }
    vector<int> dp(40001,0);
    for (auto i : primes) {
        dp[i] += 1;
        for (int j = i; j < 40001; j++) {
            dp[j] = (dp[j]%MOD + dp[j-i]%MOD) % MOD;
        }
    }
    cout << dp[n];
}
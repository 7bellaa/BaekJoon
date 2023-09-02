#include <bits/stdc++.h>
using namespace std;

vector<bool> isprime(1121, true);
vector<int> primes;
int dp[1121][15];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < 1121; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i*2; j < 1121; j += i) isprime[j] = false;
        }
    }

    dp[0][0] = 1;
    for (auto i : primes) {
        for (int j = 1120; j >= i; j--) {
            for (int k = 1; k < 15; k++) dp[j][k] += dp[j-i][k-1];
        }
    }

    int N; cin >> N;
    while (N--) {
        int a, b; cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}
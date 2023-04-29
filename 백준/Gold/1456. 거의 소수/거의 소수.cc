#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const ull N_MAX = 10000003;
bool isprime[N_MAX];
vector<ull> primes;

void make_prime(const ull N) {
    fill(isprime, isprime+N, 1);
    for (ull i = 2; i < N; i++) {
        if (isprime[i]) primes.push_back(i);
        for (ull j = i*2; j < N; j += i) {
            isprime[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ull A, B;
    cin >> A >> B;
    make_prime(N_MAX);

    ull cnt = 0;
    for (const auto i : primes) {
        ull tmp = i*i;
        if (tmp > B) break;
        while (tmp < A) tmp *= i;
        while (A <= tmp && tmp <= B) {
            cnt++;
            tmp *= i;
            if (tmp % i) break;
        }
    }
    cout << cnt;
}
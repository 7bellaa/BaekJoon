#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N_MAX = 1000000;
int mu[N_MAX];

void init() {
    mu[1] = 1;
    for (int i = 1; i < N_MAX; i++) {
        for (int j = i*2; j < N_MAX; j += i) mu[j] -= mu[i];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    ll k; cin >> k;
    ll start = 0, end = 1e11;
    while (start < end) {
        ll mid = (start + end) / 2, cnt = 0;
        for (ll i = 1; i * i <= mid; i++) {
            cnt += mu[i] * (mid / (i*i));
        }
        if (mid - cnt < k) start = mid + 1;
        else end = mid;
    }
    cout << start;
}
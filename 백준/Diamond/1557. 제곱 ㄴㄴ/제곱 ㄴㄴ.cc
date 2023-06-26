#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 45000;
int mu[N_MAX];

void init() {
    mu[1] = 1;
    for (int i = 1; i < N_MAX; i++) {
        for (int j = i<<1; j < N_MAX; j += i) mu[j] -= mu[i];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int k; cin >> k;
    long long start = 1, end = k*2;
    while (start < end) {
        long long mid = (start + end) / 2, cnt = 0;
        for (long long i = 1; i * i <= mid; i++) {
            cnt += mu[i] * (mid / (i*i));
        }
        if (cnt < k) start = mid + 1;
        else end = mid;
    }
    cout << start;
}
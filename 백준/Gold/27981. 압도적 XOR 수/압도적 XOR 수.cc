#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, k;
    cin >> n >> k;

    long long ans = 0;
    long long cmp = 2;
    for (int i = 0; i < k; i++) {
        if (n >= cmp-1) ans++;
        cmp *= 2;
    }

    long long cnt = 2;
    while (n >= cmp-1) {
        cmp *= 2;
        ans += cnt;
        cnt *= 2;
    }
    cmp -= cnt;
    if (n >= cmp) {
        ans += n - cmp + 1;
    }
    cout << ans;
}
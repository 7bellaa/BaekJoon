#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int cnt = 0, i = 2;

    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            cnt++;
        } else {
            i++;
        }
    }
    int t = 1;
    for (i = 0; i < 30; i++) {
        if (cnt <= t) break;
        t *= 2;
    }
    cout << i;
}
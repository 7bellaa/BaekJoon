#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, res = 100, sum = 0;
    for (int i = 0; i < 7; i++) {
        cin >> a;
        if (a & 1) {
            res = min({res, a});
            sum += a;
        }
    }
    sum ? cout << sum << '\n' << res : cout << -1;
    return 0;
}
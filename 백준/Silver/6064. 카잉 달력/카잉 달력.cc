#include <bits/stdc++.h>
using namespace std;

int M, N, X, Y;

int solve(int m, int n, int x, int y) {
    while (x <= m * n) {
        if ((x - y) % n == 0) return x;
        x += m;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> M >> N >> X >> Y;
        cout << solve(M, N, X, Y) << '\n';
    }
}
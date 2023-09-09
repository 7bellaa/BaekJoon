#include <bits/stdc++.h>
using namespace std;
int ans;

void solve(int n, int r, int c) {
    if (n == 0) return;

    int half = 1 << (n-1);
    if (r < half && c < half) solve(n-1, r, c);
    else {
        int size = half * half;
        if (r < half && c >= half) {
            ans += size;
            solve(n-1, r, c-half);
        } else if (r >= half && c < half) {
            ans += size * 2;
            solve(n-1, r-half, c);
        } else {
            ans += size * 3;
            solve(n-1, r-half, c-half);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    solve(n, r, c);
    cout << ans;
}

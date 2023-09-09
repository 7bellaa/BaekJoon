#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int, int> solve(int n, int m) {
    if (n == 2) {
        switch (m) {
            case 1: return {1, 1};
            case 2: return {1, 2};
            case 3: return {2, 2};
            case 4: return {2, 1};
        }  
    }
    n /= 2;
    int size = n * n;

    if (m <= size) {
        auto t = solve(n, m);
        return {t.Y, t.X};
    }
    else if (m <= size * 2) {
        auto t = solve(n, m - size);
        return {t.X, t.Y + n};
    }
    else if (m <= size * 3) {
        auto t = solve(n, m - size * 2);
        return {t.X + n, t.Y + n};
    }
    else {
        auto t = solve(n, m - size * 3);
        return {2 * n - t.Y + 1, n - t.X + 1};
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    auto ans = solve(n, m);
    cout << ans.X << ' ' << ans.Y;
}
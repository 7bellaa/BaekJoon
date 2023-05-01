#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, marble[5];
ll dp[6][6][11][11][11][11][11];

ll solve(int ppre, int pre, int a, int b, int c, int d, int e) {
    if (a+b+c+d+e == 0) return 1;
    ll &res = dp[ppre][pre][a][b][c][d][e];
    if (res != -1) return res;
    res = 0;

    if (a > 0 && ppre != 0 && pre != 0) res += solve(pre, 0, a-1, b, c, d, e);
    if (b > 0 && ppre != 1 && pre != 1) res += solve(pre, 1, a, b-1, c, d, e);
    if (c > 0 && ppre != 2 && pre != 2) res += solve(pre, 2, a, b, c-1, d, e);
    if (d > 0 && ppre != 3 && pre != 3) res += solve(pre, 3, a, b, c, d-1, e);
    if (e > 0 && ppre != 4 && pre != 4) res += solve(pre, 4, a, b, c, d, e-1);
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> marble[i];
    fill(&dp[0][0][0][0][0][0][0], &dp[5][5][10][10][10][10][10]+1, -1);

    cout << solve(5, 5, marble[0], marble[1], marble[2], marble[3], marble[4]);
}
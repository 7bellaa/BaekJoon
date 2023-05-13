#include <bits/stdc++.h>
using namespace std;

int score[301];
int dp[2][301];
int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> score[i];
    dp[0][1] = score[1];
    for (int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[0][i-2], dp[1][i-2]) + score[i];
        dp[1][i] = dp[0][i-1] + score[i];
    }

    cout << max(dp[0][n], dp[1][n]);
}
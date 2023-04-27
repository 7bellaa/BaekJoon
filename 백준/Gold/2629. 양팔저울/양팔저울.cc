#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> weight(n+1);
    for (int i = 1; i <= n; i++) cin >> weight[i];
    
    int m; cin >> m;
    vector<int> marble(m);
    for (auto &i : marble) cin >> i;

    int mx = accumulate(weight.begin(), weight.end(), 0);
    vector<vector<int>> dp(n+1, vector<int>(mx+1, 0));
    for (auto &i : dp) i[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= mx; j++) {
            if (dp[i-1][j]) dp[i][j] = 1;
            else if (j < weight[i]) {
                if (weight[i] - j <= mx && dp[i-1][weight[i]-j]) dp[i][j] = 1;
                else if (weight[i] + j <= mx && dp[i-1][weight[i]+j]) dp[i][j] = 1;
            } else {
                if (j - weight[i] <= mx && dp[i-1][j-weight[i]]) dp[i][j] = 1;
                else if (weight[i] + j <= mx && dp[i-1][weight[i]+j]) dp[i][j] = 1;
            }
        }
    }
    for (auto i : marble) {
        if (i <= mx && dp[n][i]) cout << "Y ";
        else cout << "N ";
    }
}
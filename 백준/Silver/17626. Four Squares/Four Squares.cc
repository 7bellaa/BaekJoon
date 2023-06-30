#include <bits/stdc++.h>
using namespace std;

vector<int> square;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i*i <= n; i++) square.push_back(i*i);
    
    vector<int> dp(n+1, 4);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (auto j : square) {
            if (i+j > n) break;
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[n];
}

// dp 라는걸 생각못했음
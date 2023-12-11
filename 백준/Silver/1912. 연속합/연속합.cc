#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> num;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        num.push_back(t);
    }

    int ans = num[0];
    vector<int> dp;
    dp.push_back(num[0]);

    for (int i = 1; i < n; i++) {
        if (num[i] > num[i] + dp.back()) dp.push_back(num[i]);
        else dp.push_back(dp.back() + num[i]);
        ans = max(ans, dp.back());
    }

    cout << ans;
}
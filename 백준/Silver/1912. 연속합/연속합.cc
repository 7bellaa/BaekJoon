#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> num, dp;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        num.push_back(t);
    }

    int ans = num[0];
    dp.push_back(num[0]);

    for (int i = 1; i < n; i++) {
        dp.push_back(max(num[i], dp.back() + num[i]));
        ans = max(ans, dp.back());
    }

    cout << ans;
}
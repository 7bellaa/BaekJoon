#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> num(1, 0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        num.push_back(num.back() + t);
    }

    for (int i = 1; i <= n; i++) {
        int start = 0, end = i;
        int unit = num[end] - num[start];
        if (num.back() % unit) continue;

        bool flag = true;
        while (flag && end <= n) {
            int sum = num[end] - num[start];
            if (sum < unit)
                end++;
            else if (sum == unit) {
                start = end; end++;
                if (start == n) {cout << unit << '\n'; return;}
            }
            else
                flag = false;
        }
    }

    cout << num.back() << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
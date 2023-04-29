#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "Case #" << i << ": " << "0\n";
            continue;
        }

        vector<int> v(n);
        v[0] = v[1] = 1;
        for (int j = 2; j < n; j++) v[j] = ((long long)v[j-2] + (long long)v[j-1]) % k;
        cout << "Case #" << i << ": " << v[n-1] << '\n';
    }
}
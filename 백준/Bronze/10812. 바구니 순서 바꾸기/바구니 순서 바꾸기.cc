#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    iota(a, a+n, 1);

    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        vector<int> v;
        for (int idx = k-1; idx < j; idx++) v.push_back(a[idx]);
        for (int idx = i-1; idx < k; idx++) v.push_back(a[idx]);
        auto it = v.begin();
        for (int idx = i-1; idx < j; idx++) {
            a[idx] = *it;
            it++;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
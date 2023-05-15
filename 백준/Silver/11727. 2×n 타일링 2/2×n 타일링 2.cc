#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1, 0);
    v[1] = 1;
    v[2] = 3;
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i-1] + v[i-2] * 2) % 10007;
    }
    cout << v[n];
}
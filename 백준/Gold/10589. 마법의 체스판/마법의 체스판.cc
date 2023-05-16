#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    cout << n/2 + m/2 << '\n';
    for (int i = 2; i <= n; i += 2)
        cout << i << ' ' << 1 << ' ' << i << ' ' << m << '\n';

    for (int i = 2; i <= m; i += 2)
        cout << 1 << ' ' << i << ' ' << n << ' ' << i << '\n';
}
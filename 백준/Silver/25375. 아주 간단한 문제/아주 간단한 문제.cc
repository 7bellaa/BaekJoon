#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool solve(ll a, ll b) {
    if (b % a == 0) return b/a >= 2;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (solve(a, b)) cout << "1\n";
        else cout << "0\n";
    }
}
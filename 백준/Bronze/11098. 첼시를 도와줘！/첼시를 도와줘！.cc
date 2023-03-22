#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int m; cin >> m;
        int mx = 0;
        string ms;
        while (m--) {
            string ts;
            int t;
            cin >> t >> ts;
            if (t > mx) {ms = ts; mx = t;}
        }
        cout << ms << '\n';
    }
}
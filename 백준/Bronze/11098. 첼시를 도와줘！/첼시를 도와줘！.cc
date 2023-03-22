#include <bits/stdc++.h>
using namespace std;

int main() {
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
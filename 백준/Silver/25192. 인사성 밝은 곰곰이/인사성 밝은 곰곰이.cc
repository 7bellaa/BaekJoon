#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    map<string, int> m;
    int ans = 0;
    string s;

    while (N--) {
        cin >> s;
        if (s == "ENTER") {
            ans += m.size();
            m.clear();
        } else {
            if (m.find(s) != m.end()) m[s]++;
            else m[s] = 1;
        }
    }
    ans += m.size();
    cout << ans;
}
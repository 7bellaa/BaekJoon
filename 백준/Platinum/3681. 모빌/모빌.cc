#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<ll, ll> cnt;
int total;

void init() {
    cnt.clear();
    total = 0;
    ll num = 0, depth = 0;
    string s; cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[')
            depth++;
        else if (s[i] == ']' || s[i] == ',') {
            if (isdigit(s[i-1])) {cnt[num * (1 << depth)]++; total++;}
            if (s[i] == ']') depth--;
            num = 0;
        }
        else
            num = num*10 + (s[i]-'0');
    }
    if (num) {cnt[num * (1 << depth)]++; total++;}
}

void solve() {
    int max = max_element(cnt.begin(), cnt.end(), [] (const auto &a, const auto &b) {return a.second < b.second;})->second;
    cout << total - max << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        init();
        solve();
    }
}
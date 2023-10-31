#include <bits/stdc++.h>
using namespace std;

map<string, bool> exist, observed;
int n, m;
string s;

void init() {
    getline(cin, s);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        exist[s] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        observed[s] = true;
    }
    exist["swi"] = true;
}

string solve() {
    if (exist.find("dongho") != exist.end()) return "dongho";

    int cnt = 0;
    for (auto [k, v]: exist) {
        if (observed.find(k) == observed.end()) {cnt++; s = k;}
    }
    if (cnt == 1) return s;

    if (observed.find("bumin") == observed.end() && exist.find("bumin") != exist.end())
        return "bumin";
    if (observed.find("cake") == observed.end() && exist.find("cake") != exist.end())
        return "cake";
    if (observed.find("lawyer") == observed.end() && exist.find("lawyer") != exist.end())
        return "lawyer";
    
    for (auto [k, v]: exist) {
        if (observed.find(k) == observed.end()) return k;
    }
    return "none";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    cout << solve();
}
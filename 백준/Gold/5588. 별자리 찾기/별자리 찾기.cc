#include <bits/stdc++.h>
using namespace std;

int m, n, a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m;
    set<pair<int, int>> star;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        star.insert({a, b});
    }

    cin >> n;
    set<pair<int, int>> photo;
    for (int i = 0; i < n; i++) {
        cin >> a >> b ;
        photo.insert({a, b});
    }

    auto [s1, s2] = *star.begin();
    for (auto [x1, y1] : photo) {
        x1 -= s1;
        y1 -= s2;
        bool flag = true;
        for (auto [x2, y2] : star) {
            if (photo.find({x1+x2, y1+y2}) == photo.end()) {flag = false; break;}
        }
        if (flag) {cout << x1 << ' ' << y1; return 0;}
    }
}
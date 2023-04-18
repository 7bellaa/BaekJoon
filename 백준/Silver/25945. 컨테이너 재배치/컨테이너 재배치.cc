#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    generate_n(back_inserter(v), n, [] () {return *(istream_iterator<int>{cin});});

    int m = accumulate(v.begin(), v.end(), 0);
    int cmp = m/n;
    int res1 = 0, res2 = 0;
    for (auto i : v) {
        if (i > cmp+1) res1 += i - cmp - 1;
        if (i < cmp) res2 += cmp - i;
    }
    cout << max({res1, res2});
}
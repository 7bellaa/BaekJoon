#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    generate_n(back_inserter(v), n, [] () {return *(istream_iterator<int>{cin});});
    
    int left = 0, right = 0;
    for (auto i : v) {
        if (left <= right) left += i;
        else if (left > right) right += i;
    }
    int cnt = 0, diff = abs(left - right);
    int weight[] = {100, 50, 20, 10, 5, 2, 1};
    for (auto i : weight) {
        cnt += diff / i;
        diff %= i;
    }
    cout << cnt;
}
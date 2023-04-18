#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, b, a;
    cin >> n >> b >> a;
    
    vector<int> v;
    generate_n(back_inserter(v), n, [] () {return *(istream_iterator<int>{cin});});
    sort(v.begin(), v.end());

    long long sum = 0;
    int start = 0, end = 0;
    for (; end < a; end++) {
        sum += v[end] / 2;
        if (sum > b) {
            cout << end;
            return 0;
        }
    }

    for (; end < n; end++) {
        sum += v[start++] / 2;
        sum += v[end] / 2;

        if (sum > b) {
            cout << end;
            return 0;
        }
    }
    cout << end;
}
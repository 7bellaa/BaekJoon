#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    stack<int> s;
    int n, t;
    long long cnt = 0;
    cin >> n;
    while (n--) {
        cin >> t;
        if (s.empty()) s.push(t);
        else {
            while (!s.empty() && s.top() <= t) s.pop();
            cnt += s.size();
            s.push(t);
        }
    }
    cout << cnt;
}
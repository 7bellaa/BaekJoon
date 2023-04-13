#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int B;
    cin >> s >> B;
    int a = 1, ans = 0;
    for (auto c = s.end()-1; c >= s.begin(); c--) {
        if (isdigit(*c)) ans += (*c - '0') * a;
        else ans += (*c - 'A' + 10) * a;
        a *= B;
    }
    cout << ans;
}
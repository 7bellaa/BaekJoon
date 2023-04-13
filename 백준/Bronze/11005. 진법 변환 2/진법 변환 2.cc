#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;
    string s = "";
    while (N) {
        int t = N % B;
        N /= B;
        if (t < 10) s += to_string(t);
        else s += 'A' + t - 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int max = 0, min = 99999999;
    string xs, ns;
    while (n--) {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        int t = c*10000 + b*100 + a;
        if (t > max) {max = t; xs = s;}
        if (t < min) {min = t; ns = s;}
    }
    cout << xs << '\n' << ns;
}
#include <bits/stdc++.h>
using namespace std;

map<string, float> m = {{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0}};
float a, b;

int main() {
    for (int i = 0; i < 20; i++) {
        string s1, s2;
        float x;
        cin >> s1 >> x >> s2;
        if (s2 == "P") continue;
        a += x;
        b += x * (m.find(s2)->second);
    }
    cout << b/a;
}
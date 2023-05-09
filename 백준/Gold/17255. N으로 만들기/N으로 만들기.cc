#include <bits/stdc++.h>
using namespace std;

string num;
map<string, int> m;

int solve(string s, int len) {
    if (len == 1) return 1;
    if (m.find(s) != m.end()) return m[s];

    string L(s.begin()+1, s.end()), R(s.begin(), s.end()-1);
    m[s] = solve(L, len-1);

    if (L == R) return m[s];
    m[s] += solve(R, len-1);
    return m[s];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> num;
    if (num.size() == 1) {cout << 1; return 0;}
    
    solve(num, num.size());
    cout << m[num];
}
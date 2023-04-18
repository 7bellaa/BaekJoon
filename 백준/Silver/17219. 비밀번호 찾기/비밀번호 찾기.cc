#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;

    map<string, string> notepad;
    string s1, s2;
    while (N--) {
        cin >> s1 >> s2;
        notepad[s1] = s2;
    }
    while (M--) {
        cin >> s1;
        cout << notepad[s1] << '\n';
    }
}
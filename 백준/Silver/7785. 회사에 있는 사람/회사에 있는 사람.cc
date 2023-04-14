#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> s;

    int N; cin >> N;
    while (N--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter") s.insert(s1);
        else s.erase(s.find(s1));
    }
    for (auto i = s.rbegin(); i != s.rend(); i++) cout << *i << '\n';
}
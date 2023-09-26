#include <bits/stdc++.h>
using namespace std;

bool compare(const string& s1, const string s2) {
    if (s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<string> tmp;
    while (n--) {
        string s; cin >> s;
        tmp.insert(s);
    }

    vector<string> words(tmp.begin(), tmp.end());
    sort(words.begin(), words.end(), compare);
    for (auto word : words) cout << word << '\n';
}
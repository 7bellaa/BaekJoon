#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<string, int> word;
    int N, M; cin >> N >> M;
    string s;
    while (N--) {
        cin >> s;
        if (s.length() >= M) {
            if (word.find(s) != word.end()) word[s]++;
            else word[s] = 1;
        }
    }
    vector<pair<string, int>> v = {word.begin(), word.end()};
    sort(v.begin(), v.end(), compare);
    for (auto [key, val] : v) cout << key << '\n';
}
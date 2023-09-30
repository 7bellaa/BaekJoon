#include <bits/stdc++.h>
using namespace std;

int T, N;
string s;

int diff(string s1, string s2) {
    int d = 0;
    for (int i = 0; i < 4; i++) {
        if (s1[i] != s2[i]) d++;
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<string> mbti;
        for (int i = 0; i < N; i++) {
            cin >> s;
            mbti.push_back(s);
        }
        if (N >= 33) {cout << 0 << '\n'; continue;}

        int ans = 12;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    ans = min(ans, diff(mbti[i], mbti[j]) + diff(mbti[j], mbti[k]) + diff(mbti[k], mbti[i]));
                }
            }
        }
        cout << ans << '\n';
    }
}
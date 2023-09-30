#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> v(N);
    for (auto &i : v) cin >> i;
    stack<int> wait;
    int pass = 0;

    for (auto i : v) {
        if (i - pass == 1) {pass++; continue;}
        if (wait.empty()) {wait.push(i); continue;}
        while (!wait.empty()) {
            if (wait.top() - pass == 1) {wait.pop(); pass++;}
            else break;
        }
        if (wait.empty() || i < wait.top()) wait.push(i);
        else {cout << "Sad"; return 0;}
    }
    cout << "Nice";
}
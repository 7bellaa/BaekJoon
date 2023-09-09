#include <bits/stdc++.h>
using namespace std;

int N, S, t, cnt;
vector<int> v;

void dfs(int sum, int idx) {
    if (idx == N) return;
    if (sum + v[idx] == S) cnt++;
    dfs(sum + v[idx], idx+1);
    dfs(sum, idx+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }
    dfs(0, 0);
    cout << cnt;
}
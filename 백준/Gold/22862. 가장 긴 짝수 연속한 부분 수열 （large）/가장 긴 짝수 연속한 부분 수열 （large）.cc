#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (auto &i : v) cin >> i;

    int start = 0, end = 0, cnt = 0, ans = 0;

    for (start = 0; start < N; start++) {
        if (cnt > 0 && (v[start-1] % 2 == 1)) cnt--;
        while (end < N && cnt <= K) {
            if (v[end++] % 2 == 1) cnt++;
        }
        ans = max(ans, end - start - cnt);
    }

    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> v(n+1);
    v[n] = d;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int start = 0, end = *max_element(v.begin(), v.end());
    int ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int pre_island = 0, cnt = 0;;
        for (auto island : v) {
            if (island - pre_island >= mid) {
                pre_island = island;
                cnt++;
            }
        }

        if (cnt >= n-m+1) {
            ans = max(ans, mid);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << ans;
}
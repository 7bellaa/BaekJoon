#include <bits/stdc++.h>
using namespace std;

int n, k, arr[1000001], ans, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int l = 0, r = 0; r < n; r++) {
    if (arr[r] & 1)
      cnt++;
    while (cnt > k) {
      if (arr[l++] & 1)
        cnt--;
    }
    ans = max(ans, r - l + 1 - cnt);
  }

  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int n, arr[100001], cnt[100001];
long long ans;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void solve() {
  for (int l = 0, r = 0; r < n; r++) {
    ++cnt[arr[r]];
    while (cnt[arr[r]] > 1) {
      --cnt[arr[l++]];
    }
    ans += r - l + 1;
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
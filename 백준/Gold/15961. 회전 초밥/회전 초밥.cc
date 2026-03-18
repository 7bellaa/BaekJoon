#include <bits/stdc++.h>
using namespace std;

int N, d, k, c, ans, kind;
int arr[3003003], cnt[3003];

void init() {
  cin >> N >> d >> k >> c;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  for (int i = 0; i < k - 1; i++) {
    arr[N + i] = arr[i];
  }
  N += k - 1;
}

void solve() {
  for (int l = 0, r = 0; r < N; r++) {
    if (++cnt[arr[r]] == 1)
      kind++;
    while (r - l >= k) {
      if (--cnt[arr[l++]] == 0)
        kind--;
    }
    if (cnt[c] > 0)
      ans = max(ans, kind);
    else
      ans = max(ans, kind + 1);
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
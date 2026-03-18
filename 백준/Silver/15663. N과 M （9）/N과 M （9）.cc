#include <bits/stdc++.h>
using namespace std;

int n, m, arr[9], ans[9];
bool vis[9];

void f(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }

  int last = 0;

  for (int i = 0; i < n; i++) {
    if (vis[i] || arr[i] == last)
      continue;
    vis[i] = true;
    last = arr[i];
    ans[k] = arr[i];
    f(k + 1);
    vis[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);
  f(0);
}
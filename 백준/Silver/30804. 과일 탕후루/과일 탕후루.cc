#include <bits/stdc++.h>
using namespace std;

int n, ans;
int arr[200005], ncnt[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int kind = 0;
  for (int l = 0, r = 0; r < n; r++) {
    if (ncnt[arr[r]]++ == 0) {
      kind++;
    }
    while (kind > 2) {
      if (--ncnt[arr[l]] == 0) {
        kind--;
      }
      l++;
    }
    ans = max(ans, r - l + 1);
  }

  cout << ans;
}
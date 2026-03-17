#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int sum = 0, idx, m;
  string s;
  cin >> s;

  for (int i = 0; i < 12; i++) {
    if (s[i] == '*')
      idx = i;
    else
      sum += (i & 1) ? ((s[i] - '0') * 3) : (s[i] - '0');
  }
  m = (10 - (s[12] - '0')) % 10;
  sum %= 10;

  int ans = (10 + m - sum) % 10;
  if (idx & 1)
    cout << (100 - 3 * ans) % 10;
  else
    cout << ans;
}
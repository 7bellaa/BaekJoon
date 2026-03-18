#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1, lo, hi, ans, num1, num2;
int arr[200001], ncnt[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  num1 = arr[0];
  ncnt[num1]++;
  while (hi < n - 1) {
    if (arr[hi + 1] == num1) {
      ncnt[num1]++;
      hi++;
      continue;
    }
    if (arr[hi + 1] == num2) {
      ncnt[num2]++;
      hi++;
      continue;
    }
    if (cnt == 1) {
      hi++;
      num2 = arr[hi];
      ncnt[num2]++;
      cnt++;
      continue;
    }

    ans = max(ans, hi - lo + 1);
    while (lo < hi) {
      lo++;
      (arr[lo - 1] == num1) ? (ncnt[num1]--) : (ncnt[num2]--);

      if (ncnt[num2] == 0) {
        num2 = 0;
        break;
      } else if (ncnt[num1] == 0) {
        num1 = num2;
        num2 = 0;
        break;
      }
    }
    cnt--;
  }
  ans = max(ans, hi - lo + 1);
  cout << ans;
}
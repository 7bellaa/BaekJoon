#include <bits/stdc++.h>
using namespace std;

int n, height[1001];

void solve() {
  int left = 1, right = 1000, left_max = 0, right_max = 0, area = 0;
  while (left <= right) {
    left_max = max(left_max, height[left]);
    right_max = max(right_max, height[right]);

    if (left_max < right_max) {
      area += left_max;
      left++;
    } else {
      area += right_max;
      right--;
    }
  }
  cout << area;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;

  int l, h;
  for (int i = 0; i < n; i++) {
    cin >> l >> h;
    height[l] = h;
  }

  solve();
}
#include <bits/stdc++.h>
using namespace std;

int h, w;
int height[501];

void solve() {
  int left = 0, right = w - 1, left_max = 0, right_max = 0, water = 0;
  while (left < right) {
    left_max = max(left_max, height[left]);
    right_max = max(right_max, height[right]);

    if (left_max < right_max)
      water += left_max - height[left++];
    else
      water += right_max - height[right--];
  }
  cout << water;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  for (int i = 0; i < w; i++)
    cin >> height[i];

  solve();
}
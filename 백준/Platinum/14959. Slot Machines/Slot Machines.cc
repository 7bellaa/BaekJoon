#include <bits/stdc++.h>
using namespace std;

vector<int> failure(const vector<int>& arr) {
  vector<int> F(arr.size() + 1);
  for (int i = 1, j = 0; i < arr.size(); i++) {
    while (j > 0 && arr[i] != arr[j]) j = F[j - 1];
    if (arr[i] == arr[j]) F[i] = ++j;
  }
  return F;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;

  vector<int> arr(N);
  for (int i = N - 1; i >= 0; i--) cin >> arr[i];
  vector<int> F = failure(arr);

  int i = max_element(F.begin(), F.end()) - F.begin();
  int len = i + 1;

  int p = len - F[i];
  int k = N - len;
  cout << k << ' ' << p;
}
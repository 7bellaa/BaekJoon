#include <bits/stdc++.h>
using namespace std;

int n, m, arr[9];
bool vis[9];
vector<int> ans;

void print_ans() {
  for (auto i : ans)
    cout << i << ' ';
  cout << '\n';
}

void f(int x) {
  if (x == m) {
    print_ans();
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] || arr[i] == arr[i - 1])
      continue;
    vis[i] = true;
    ans.push_back(arr[i]);
    f(x + 1);
    vis[i] = false;
    ans.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  f(0);
}
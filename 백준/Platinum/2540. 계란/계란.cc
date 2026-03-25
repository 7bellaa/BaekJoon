#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans[2000];  // egg, idx
int idx = 0;

void solve(vector<pair<int, int>> v) {
  sort(v.begin(), v.end());
  auto a = v[0], b = v[1], c = v[2], d = v[3];
  int sum = a.first + b.first + c.first;

  if (sum == 0) {
    return;
  } else if (sum & 1 || sum == c.first) {
    a.first += 2;
    c.first--;
    d.first--;
  } else if (a.first + b.first < c.first) {
    a.first += 2;
    b.first--;
    c.first--;
  } else {
    d.first += 2;
    b.first--;
    c.first--;
  }

  vector<pair<int, int>> t = {a, b, c, d};
  sort(t.begin(), t.end(),
       [](const pair<int, int>& p1, const pair<int, int>& p2) {
         if (p1.second == p2.second) return p1.first < p2.first;
         return p1.second < p2.second;
       });
  ans[idx++] = t;
  solve(t);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, x;
  cin >> k;

  vector<pair<int, int>> v;
  for (int i = 0; i < 4; i++) {
    cin >> x;
    v.push_back({x, i});
  }
  ans[idx++] = v;
  solve(v);

  for (int i = 0; i < idx; i++) {
    for (auto j : ans[i]) cout << j.first << ' ';
    cout << '\n';
  }
}
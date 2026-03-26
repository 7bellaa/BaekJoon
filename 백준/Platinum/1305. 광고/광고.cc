#include <bits/stdc++.h>
using namespace std;

vector<int> failure(const string& s) {
  vector<int> F(s.length());
  for (int i = 1, j = 0; i < s.length(); i++) {
    while (j > 0 && s[i] != s[j]) j = F[j - 1];
    if (s[i] == s[j]) F[i] = ++j;
  }
  return F;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  auto F = failure(s);
  cout << n - F[n-1];
}
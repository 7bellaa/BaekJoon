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

void solve(const string& T, const string& P) {
  auto F = failure(P);
  string ans = "";
  vector<int> state;

  for (int i = 0, j = 0; i < T.length(); i++) {
    while (j > 0 && T[i] != P[j]) j = F[j - 1];
    if (T[i] == P[j]) j++;

    ans.push_back(T[i]);
    state.push_back(j);

    if (j == P.length()) {
      ans.resize(ans.length() - j);
      state.resize(state.size() - j);

      j = state.empty() ? 0 : state.back();
    }
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string t, p;
  cin >> t >> p;
  solve(t, p);
}
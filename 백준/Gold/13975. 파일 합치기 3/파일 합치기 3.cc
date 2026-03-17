#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = long long;
const int N_MAX = 1e6 + 1;

void solve() {
  int n;
  cin >> n;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    pq.push(t);
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    ans += a + b;
    pq.push(a + b);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
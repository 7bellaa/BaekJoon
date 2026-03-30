#include <bits/stdc++.h>
using namespace std;

struct Item {
  int v, c, k;
  friend istream& operator>>(istream& is, Item& item) {
    is >> item.v >> item.c >> item.k;
    return is;
  }
};

vector<Item> items;
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    Item tmp;
    cin >> tmp;
    for (int i = 0; i < 15 && tmp.k / (1 << i); i++) {
      items.push_back({tmp.v * (1 << i), tmp.c * (1 << i), 1});
      tmp.k -= 1 << i;
    }
    if (tmp.k > 0) items.push_back({tmp.v * tmp.k, tmp.c * tmp.k, 1});
  }

  vector<int> dp(M + 1, 0);
  for (int i = 0; i < items.size(); i++) {
    for (int j = M; j >= items[i].v; j--) {
      dp[j] = max(dp[j], dp[j - items[i].v] + items[i].c);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}
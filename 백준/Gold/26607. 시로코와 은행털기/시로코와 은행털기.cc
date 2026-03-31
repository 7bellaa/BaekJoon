#include <bits/stdc++.h>
using namespace std;

bitset<16001> dp[81];  // dp[i][w]: i명 뽑았을때 A_i의 합이 w가 될수있는가

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K, X;
  cin >> N >> K >> X;
  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;

    for (int k = K; k >= 1; k--) {
      dp[k] |= dp[k - 1] << a;
    }
  }

  // int mx = 0;
  int ans = 0;
  for (int w = 0; w <= K * X; w++) {
    if (!dp[K][w]) continue;
    // if (abs((double)K * X / 2 - w) < abs((double)K * X / 2 - mx)) mx = w;
    // double 형변환하기 싫어서 전체에 2를 곱함
    // if (abs(K * X - 2 * w) < abs(K * X - 2 * mx)) mx = w;

    // 원래 우리가 찾으려는 w는 w * (K*X - w)가 최대가 되는 w이다.
    // 그래서 그냥 저걸 그대로 계산해서 저게 최대가 될때마다 mx 갱신해주면 된다.
    // ** 이걸 더 추천 **
    ans = max(ans, w * (K * X - w));
  }
  cout << ans;
}
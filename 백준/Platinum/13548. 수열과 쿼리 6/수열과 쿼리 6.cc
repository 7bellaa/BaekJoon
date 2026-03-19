#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100001;
int N, M, sq = 1, max_freq;
int arr[N_MAX], cnt[N_MAX], cntcnt[N_MAX], ans[N_MAX];

struct Query {
  int L, R, idx;

  bool operator<(const Query &o) const {
    // division by zero 주의
    int i1 = L / sq, i2 = o.L / sq;
    if (i1 == i2)
      return R < o.R;
    return i1 < i2;
  }
};

vector<Query> Q;

void init() {
  cin >> N;
  sq = sqrt(N);
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  cin >> M;
  int tl, tr;
  for (int i = 0; i < M; i++) {
    cin >> tl >> tr;
    Q.push_back({tl - 1, tr - 1, i});
  }

  sort(Q.begin(), Q.end());
}

void plus_count(int num) {
  cntcnt[cnt[num]++]--;
  cntcnt[cnt[num]]++;
  max_freq = max(max_freq, cnt[num]);
}

void minus_count(int num) {
  if (cnt[num] == max_freq && cntcnt[cnt[num]] == 1)
    max_freq--;
  cntcnt[cnt[num]--]--;
  cntcnt[cnt[num]]++;
}

void solve() {
  int l = 0, r = 0;
  // 초기값 설정 (init에서 하는게 나을수도)
  ++cntcnt[++cnt[arr[0]]];
  for (auto q : Q) {
    // 구간 증가
    while (l > q.L) {
      plus_count(arr[--l]);
    }
    while (r < q.R) {
      plus_count(arr[++r]);
    }
    // 구간 감소
    while (l < q.L) {
      minus_count(arr[l++]);
    }
    while (r > q.R) {
      minus_count(arr[r--]);
    }

    ans[q.idx] = max_freq;
  }
  for (int i = 0; i < M; i++)
    cout << ans[i] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  solve();
}
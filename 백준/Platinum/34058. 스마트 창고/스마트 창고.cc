#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 501;

int N, M;
int prefix_sum[N_MAX][N_MAX];
int final_ans[N_MAX][N_MAX]; // 최종 정답용 보드 
int current_ans[N_MAX][N_MAX]; // 3차원 500MB를 대체해줄 임시 캐시 공간 (1MB)

void init() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> prefix_sum[i][j];
      prefix_sum[i][j] += prefix_sum[i][j - 1] + prefix_sum[i - 1][j] -
                          prefix_sum[i - 1][j - 1];
      final_ans[i][j] = -1e9; // 정답 배열은 최솟값으로 미리 초기화
    }
  }
}

void solve() {
  vector<int> col_sum(N_MAX), dp1(N_MAX), dp2(N_MAX + 1);

  // 1. 왼쪽 경계(j1)를 고정합니다.
  for (int j1 = 1; j1 <= M; j1++) {
    
    // 2. 오른쪽 경계(j2)를 늘려가며 구한 결과들을 current_ans에 임시로 모아둡니다.
    for (int j2 = j1; j2 <= M; j2++) {
      
      for (int i = 1; i <= N; i++)
        col_sum[i] = prefix_sum[i][j2] - prefix_sum[i][j1 - 1] -
                     prefix_sum[i - 1][j2] + prefix_sum[i - 1][j1 - 1];
      
      for (int i = 1; i <= N; i++)
        dp1[i] = max(col_sum[i], dp1[i - 1] + col_sum[i]);

      for (int i = N; i >= 1; i--)
        dp2[i] = max(col_sum[i], dp2[i + 1] + col_sum[i]);

      // 3차원 배열을 쌓지 않고, 덮어쓰기가 가능한 2차원 공간만 재활용!
      for (int r = 1; r <= N; r++)
        current_ans[r][j2] = dp1[r] + dp2[r] - col_sum[r];
    }

    // 3. Suffix Max 전파 (핵심)
    // 현재 j1이 고정된 상태이므로, 'j1 <= j <= j2' 범위를 포함하기 위해
    // j2를 맨 뒤에서부터 거꾸로 역추적하며 누적 최댓값을 정답 보드에 단숨에 부어버립니다.
    for (int r = 1; r <= N; r++) {
      int mx = -1e9;
      for (int j = M; j >= j1; j--) {
        mx = max(mx, current_ans[r][j]); 
        final_ans[r][j] = max(final_ans[r][j], mx);
      }
    }
  }

  // 4. 끝나면 모든 영역이 아름답게 중첩되어 있으므로 바로 O(N*M) 출력!
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cout << final_ans[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  init();
  solve();
  
  return 0;
}

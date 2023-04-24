#include <bits/stdc++.h>
using namespace std;
// 수빈이가 x2를 해서 10만을 나가는 경우도 있을 수 있기 때문에 범위를 20만 까지로 잡는게 맞다.
// 하지만 x2 해서 10만을 나간 후에 -1를 하는 것보다 먼저 -1을 한 뒤에 x2를 하는게 더 이득이므로 10만을 나가지 않는게 답이라는 걸 보장할 수 있다.
const int N_MAX = 1000001;
int dist[N_MAX];

int N, K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    fill(dist, dist+N_MAX, -1);
    queue<int> Q;
    dist[N] = 0;
    Q.push(N);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == K) {
            cout << dist[cur];
            return 0;
        }
        
        int tmp[] = {cur-1, cur+1, cur*2};
        for (auto now : tmp) {
            if (now < 0 || now >= N_MAX) continue;
            if (dist[now] >= 0) continue;

            dist[now] = dist[cur] + 1;
            Q.push(now);
        }
    }
}
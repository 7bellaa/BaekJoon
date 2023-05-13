#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100001;
int dist[N_MAX];
int N, K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    fill (dist, dist+N_MAX, -1);
    queue<int> Q;
    Q.push(N);
    dist[N] = 0;

    while (dist[K] == -1) {
        int cur = Q.front(); Q.pop();
        int nxt[3] = {cur*2, cur-1, cur+1};
        for (int i = 0; i < 3; i++) {
            if (nxt[i] < 0 || nxt[i] >= N_MAX || dist[nxt[i]] != -1) continue;
            if (i == 0) dist[nxt[i]] = dist[cur];
            else dist[nxt[i]] = dist[cur] + 1;
            Q.push(nxt[i]);
        }
    }
    cout << dist[K];
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    S--; G--;

    int cnt = 0;
    if (G == S) {
        cout << cnt; return 0;
    } else if (G > S) {
        if (U == 0) {cout << "use the stairs"; return 0;}
        cnt += (G - S) / U;
        S += U * cnt;
    } else {
        if (D == 0) {cout << "use the stairs"; return 0;}
        cnt += (S - G) / D;
        S -= D * cnt;
    }

    vector<int> dist(F, -1);
    int dx[2] = {U, -D};
    queue<int> Q;
    dist[S] = cnt;
    Q.push(S);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == G) {cout << dist[cur]; return 0;}

        for (int dir = 0; dir < 2; dir++) {
            int nx = cur + dx[dir];

            if (nx < 0 || nx >= F) continue;
            if (dist[nx] >= 0) continue;

            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << "use the stairs";
}
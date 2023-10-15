#include <bits/stdc++.h>
using namespace std;

int N, M, diff = numeric_limits<int>::max();
int board[20][20];
bool vis[20];

void calculateDiff() {
    int res1 = 0, res2 = 0;
    vector<int> team1, team2;
    for (int i = 0; i < N; i++) {
        if (vis[i]) team1.push_back(i);
        else team2.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            res1 += board[team1[i]][team1[j]];
            res2 += board[team2[i]][team2[j]];
        }
    }
    diff = min(diff, abs(res1 - res2));
}

void dfs(int prev, int cnt) {
    if (cnt == M) {
        calculateDiff();
        return;
    }

    for (int i = prev; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i, cnt+1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    M = N/2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> board[i][j];
    }

    dfs(0, 0);
    cout << diff;
}
#include <bits/stdc++.h>
using namespace std;

char board[501][501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> board[i][j];
    }

    vector<map<char, int>> v(K*K);
    for (int i = 0; i < N/K; i++) {
        for (int j = 0; j < M/K; j++) {
            for (int x = 0; x < K; x++) {
                for (int y = 0; y < K; y++) {
                    if (v[x*K+y].find(board[i*K+x][j*K+y]) != v[x*K+y].end()) v[x*K+y][board[i*K+x][j*K+y]]++;
                    else v[x*K+y][board[i*K+x][j*K+y]] = 1;
                }
            }
        }
    }

    int num = N*M/K/K;
    int cnt = 0;
    vector<vector<char>> ans(K, vector<char>(K));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            auto it = max_element(v[i*K+j].begin(), v[i*K+j].end(), [](const auto &x, const auto &y) {return x.second < y.second;});
            ans[i][j] = it->first;
            cnt += num-it->second;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < N/K; i++) {
        for (auto &s : ans) {
            for (int j = 0; j < M/K; j++) {
                for (auto c : s) cout << c;
            }
            cout << '\n';
        }
    }
}
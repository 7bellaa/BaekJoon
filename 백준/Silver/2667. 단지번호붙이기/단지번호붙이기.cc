#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[26];
bool vis[26][26];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '0' || vis[i][j]) continue;
            cnt++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            
            int width = 1;
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == '0' || vis[nx][ny]) continue;

                    width++;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            ans.push_back(width);
        }
    }
    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << '\n';
}
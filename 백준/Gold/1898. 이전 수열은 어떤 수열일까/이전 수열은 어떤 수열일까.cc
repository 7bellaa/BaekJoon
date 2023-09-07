#include <bits/stdc++.h>
using namespace std;

vector<int> v(50001);
vector<int> vis(50001);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vis[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int cur = v[i];
        if (vis[cur] == -1 || vis[cur-1] == -1 || cur == 1) continue;
        if (vis[cur] < vis[cur-1]) {
            iter_swap(v.begin() + vis[cur], v.begin() + vis[cur-1]);
            vis[cur] = vis[cur-1] = -1;
        }
    }
    for (int i = 0; i < n; i++) cout << v[i] << ' ';
}
#include <bits/stdc++.h>
using namespace std;

bool vis[202][202];

bool isCheck() {
    fill(&vis[0][0], &vis[201][202], 0);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    queue<tuple<int, int, int>> Q;
    Q.push({s1.size(), s2.size(), s3.size()});

    while (!Q.empty()) {
        int a, b, c;
        tie(a, b, c) = Q.front(); Q.pop();

        if (a + b + c == 0) return true;

        if (a > 0 && s1[a-1] == s3[c-1] && !vis[a-1][b]) {
            vis[a-1][b] = 1;
            Q.push({a-1, b, c-1});
        }
        if (b > 0 && s2[b-1] == s3[c-1] && !vis[a][b-1]) {
            vis[a][b-1] = 1;
            Q.push({a, b-1, c-1});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        if (isCheck()) cout << "Data set " << i << ": yes\n";
        else cout << "Data set " << i << ": no\n";
    }
}
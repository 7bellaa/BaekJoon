#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int D(int a) {
    return a * 2 % 10000;
}
int S(int a) {
    return (10000 + a - 1) % 10000;
}
int L(int a) {
    return (a%1000) * 10 + (a/1000);
}
int R(int a) {
    return (a%10)*1000 + a/10;
}

void solve(int a, int b) {
    vector<string> dist(10000, "none");
    queue<int> Q;
    Q.push(a);
    dist[a] = "";

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int nx1 = D(cur), nx2 = S(cur), nx3 = L(cur), nx4 = R(cur);

        if (dist[nx1] == "none") {
            dist[nx1] = dist[cur] + "D";
            if (nx1 == b) {cout << dist[nx1] << '\n'; return;}
            Q.push(nx1);
        }
        if (dist[nx2] == "none") {
            dist[nx2] = dist[cur] + "S";
            if (nx2 == b) {cout << dist[nx2] << '\n'; return;}
            Q.push(nx2);
        }
        if (dist[nx3] == "none") {
            dist[nx3] = dist[cur] + "L";
            if (nx3 == b) {cout << dist[nx3] << '\n'; return;}
            Q.push(nx3);
        }
        if (dist[nx4] == "none") {
            dist[nx4] = dist[cur] + "R";
            if (nx4 == b) {cout << dist[nx4] << '\n'; return;}
            Q.push(nx4);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> A >> B;
        solve(A, B);
    }
}
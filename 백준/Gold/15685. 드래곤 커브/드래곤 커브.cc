#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

pair<int, int> swap(pair<int, int> &c, int a, int b) {
    auto [x, y] = c;
    x -= a; y -= b;
    int tmp = x;
    x = y; y = tmp;
    return {-x+a, y+b};
}

void make_curve(int cur, int gen, vector<pair<int, int>> &coordinate) {
    if (cur == gen) {
        for (auto [x,y] : coordinate) board[y][x] = 1;
        return;
    }
    auto [x2, y2] = coordinate.back();
    auto [x1, y1] = *(coordinate.end()-2);
    
    vector<pair<int, int>> tmp;
    for (auto it = coordinate.rbegin()+1; it != coordinate.rend(); it++) {
        tmp.push_back(swap(*it, x2, y2));
    }
    coordinate.insert(coordinate.end(), tmp.begin(), tmp.end());
    make_curve(cur+1, gen, coordinate);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while (N--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<pair<int, int>> v = {{x,y}, {x+dx[d], y+dy[d]}};
        make_curve(0, g, v);
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j]) {
                if (board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
            }
        }
    }
    cout << cnt;
}
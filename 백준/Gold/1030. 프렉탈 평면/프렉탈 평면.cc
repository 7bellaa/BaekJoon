#include <bits/stdc++.h>
using namespace std;

int s, n, k, r1, r2, c1, c2;
int base[8][8];

int wb(int size, int x, int y) {
    if (size == n) return base[x][y];
    int unit = size / n;
    int ux = x / unit, uy = y / unit;
    if (base[ux][uy]) return 1;

    return wb(unit, x%unit, y%unit);
}

void init() {
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    int i = (n-k)/2, j = (n-k)/2;
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) base[i+x][j+y] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    if (s == 0) {cout << 0; return 0;}

    int size = 1;
    while (s--) size *= n;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) cout << wb(size, i, j);
        cout << '\n';
    }
}
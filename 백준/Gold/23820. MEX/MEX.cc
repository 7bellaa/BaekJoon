#include <bits/stdc++.h>
using namespace std;

const int P_MAX = 2000003;
bool num[P_MAX+1];
bool check[P_MAX+1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        num[tmp] = 1;
    }

    if (!num[0]) {cout << 0; return 0;}

    for (int i = 1; i <= P_MAX; i++) {
        if (!num[i]) continue;
        for (int j = 1; j <= P_MAX/i; j++) {
            if (!num[j]) continue;
            check[i * j] = 1;
        }
    }
    for (int i = 1; i <= P_MAX; i++) {
        if (!check[i]) {cout << i; break;}
    }
}
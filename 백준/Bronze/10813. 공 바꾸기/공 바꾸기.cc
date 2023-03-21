#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    iota(a, a+n, 1);
    while (m--) {
        int i, j;
        cin >> i >> j;
        swap(a[i-1], a[j-1]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
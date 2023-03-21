#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int *pa = new int[n]{};
    while (m--) {
        int a,b,c;
        cin >> a >> b >> c;
        for (int i = a-1; i < b; i++) pa[i] = c;
    }
    for (int i = 0; i < n; i++) cout << pa[i] << ' ';
}
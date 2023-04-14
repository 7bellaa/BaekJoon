#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 1;
    while (N--) ans *= 2;
    ans += 1;
    cout << ans * ans;
}

// pow double 범위 문제
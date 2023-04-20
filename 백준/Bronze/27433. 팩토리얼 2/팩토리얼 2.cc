#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
    if (n < 2) return 1;
    return n * f(n-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    cout << f(n);
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n; cin >> n;
    ll ans = 1;
    for (; n > 0; n--) {
        ans *= n;
        while (!(ans % 10)) ans /= 10;
        ans %= 1000000000000;
    }
    cout.width(5);
    cout.fill('0');
    cout << ans % 100000;
}
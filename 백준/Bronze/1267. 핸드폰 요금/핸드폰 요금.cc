#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, i, x=0, y=0;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
        x += (a[i]/30 + 1) * 10;
        y += (a[i]/60 + 1) * 15;
    }
    if (x < y) cout << 'Y' << ' ' << x;
    else if (x > y) cout << 'M' << ' ' << y;
    else cout << "Y M " << x;
    return 0;
}
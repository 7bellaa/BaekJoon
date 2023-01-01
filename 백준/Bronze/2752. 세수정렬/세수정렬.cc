#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int m = *min_element(a, a+3);
    int mx = *max_element(a, a+3);
    cout << m << ' ';
    for (int i : a)
        if (m < i && i < mx) cout << i << ' ';
    cout << mx;
    return 0;
}
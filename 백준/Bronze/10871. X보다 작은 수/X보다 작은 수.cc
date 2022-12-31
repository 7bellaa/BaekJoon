#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, tmp, i;
    cin >> n >> x;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp < x) cout << tmp << ' ';
    }
    return 0;
}
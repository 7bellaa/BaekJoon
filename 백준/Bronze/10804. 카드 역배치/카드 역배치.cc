#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int a[21], i, j, x, y;
    for (i = 1; i < 21; i++) a[i] = i;
    for (i = 0; i < 10; i++) {
        cin >> x >> y;
        reverse(a+x, a+y+1);
    }
    for (i = 1; i < 21; i++) cout << a[i] << ' ';
    return 0;
}
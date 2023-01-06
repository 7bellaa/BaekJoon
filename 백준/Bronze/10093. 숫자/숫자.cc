#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    long long a[2], i;
    cin >> a[0] >> a[1];
    sort(a, a+2);
    if (a[0] == a[1])
        cout << 0;
    else {
        cout << a[1]-a[0]-1 << '\n';
        for (i = a[0]+1; i < a[1]; i++) cout << i << ' ';
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, a, b, i;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> a >> b;
        cout << a+b << '\n';
    }
    return 0;
}
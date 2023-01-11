#include <iostream>
using namespace std;

int main(void) {
    int n, v, cnt=0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> v;
    for (auto i : a) {
        if (i == v) cnt++;
    }
    cout << cnt;
    return 0;
}